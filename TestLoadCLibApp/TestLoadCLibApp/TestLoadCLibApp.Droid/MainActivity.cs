using System;

using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;
using System.Runtime.InteropServices;

namespace TestLoadCLibApp.Droid
{
	[Activity (Label = "TestLoadCLibApp.Droid", MainLauncher = true, Icon = "@drawable/icon")]
	public class MainActivity : Activity
	{
		int count = 1;

		protected override void OnCreate (Bundle bundle)
		{
			base.OnCreate (bundle);
            IntPtr ptr = CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass();
            CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber(ptr, 12345);
            count = CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber(ptr);
            CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass(ptr);
			// Set our view from the "main" layout resource
			SetContentView (Resource.Layout.Main);

			// Get our button from the layout resource,
			// and attach an event to it
			Button button = FindViewById<Button> (Resource.Id.myButton);
			
			button.Click += delegate {
				button.Text = string.Format ("{0} clicks!", count++);
			};
		}

        [DllImport("SeparateCLib")]
        public static extern IntPtr CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass();
        [DllImport("SeparateCLib")]
        public static extern void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass(IntPtr pCUnmanagedCPPCodeClass);

        [DllImport("SeparateCLib")]
        public static extern int CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber(IntPtr pCUnmanagedCPPCodeClass);
        [DllImport("SeparateCLib")]
        public static extern void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber(IntPtr pCUnmanagedCPPCodeClass, int newNumber);
    }
}


