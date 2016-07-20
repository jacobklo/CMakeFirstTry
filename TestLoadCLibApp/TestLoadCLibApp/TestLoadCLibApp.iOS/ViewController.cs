using System;

using UIKit;

namespace TestLoadCLibApp.iOS
{
	public partial class ViewController : UIViewController
	{
		int count = 1;
		IntPtr m_CUnmanagedCPPCodeClass;

		public ViewController (IntPtr handle) : base (handle)
		{
			m_CUnmanagedCPPCodeClass = Wrapper.CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass ();
		}

		~ViewController()
		{
			Wrapper.CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass(m_CUnmanagedCPPCodeClass);
		}
		public override void ViewDidLoad ()
		{
			base.ViewDidLoad ();
			// Perform any additional setup after loading the view, typically from a nib.
			Button.AccessibilityIdentifier = "myButton";
			Button.TouchUpInside += delegate {
				count++;
				Wrapper.CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber (m_CUnmanagedCPPCodeClass, count);

				var title = string.Format ("{0} clicks!", Wrapper.CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber(m_CUnmanagedCPPCodeClass));
				Button.SetTitle (title, UIControlState.Normal);
			};
		}

		public override void DidReceiveMemoryWarning ()
		{
			base.DidReceiveMemoryWarning ();
			// Release any cached data, images, etc that aren't in use.
		}
	}
}

