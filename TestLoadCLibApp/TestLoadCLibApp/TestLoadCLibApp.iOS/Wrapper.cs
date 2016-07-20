using System;
using System.Runtime.InteropServices;

namespace TestLoadCLibApp.iOS
{
	public class Wrapper
	{
		public Wrapper ()
		{
		}

		[DllImport("__Internal", EntryPoint = "CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass")]
		public static extern IntPtr CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_CreateClass();

		[DllImport("__Internal", EntryPoint = "CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber")]
		public static extern Int32 CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_GetNumber( IntPtr pObject );

		[DllImport("__Internal", EntryPoint = "CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass")]
		public static extern void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_DestroyCLass( IntPtr pObject);

		[DllImport("__Internal", EntryPoint = "CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber")]
		public static extern void CPPCLASSWRAPPER_CUnmanagedCPPCodeClass_SetNumber( IntPtr pObject, int newNumber);

	}
}

