Project : CMakeFirstTry
Author : Jacob Lo

Description
-----------
This is a sample project to show how to use CMake.
This is also using the most standand easy way a workspace should have. As least what Jacob Lo research.


How To Use
----------
Either download CMake GUI, or pull from Jacob's another repo : CMakeApp
If you want to develop the library (JLib), then
You can use CMake the generate workspaces. Use genVS2015.bat or genXCode.sh
If you want to use the library (LoadCLib) in Android or iOS, there is a TestLoadCLibApp Xamarin solution.
Android version needs to use SeparateCLib for now.
iOS version needs to generate XCode workspace by genXCode.sh first, then use the MakeFile to generate the static library, then you can import it to Xamarin iOS project.


Explain
-------
JLib : This is a library, every business logic implementation should be here. Everything platform neutral should implemente here. But not Application logic. Those are platform specific.

RunJLib : For every subJLib categories, there is a very simple application in this RunJLib. Just a simple test for JLib sub-categories to work.

TestJLib : This is the unit test for JLib.

LoadCLib : This is just created to test if a CPP library can be build and import to Xamarin cross platform. For now, this is working for iOS. With MakeFile generated static library, you can import to the Xamarin solution as "libLoadCLibSDK.a"

SeparateCLib : This is the stupid part. SeparateCLib is created by Visual Studio Xamarin as a cross platform Library workspace. It is the adding/ link each cpp files from LoadCLib (DON'T COPY). This SeparateCLib project than is imported to the TestLoadCLibApp solution. Then we can debug/run on Android from there.

TestLoadCLibCpp : This is Xamarin Cross platform solution. include Android and iOS platform. develop in C#.

genVS2015.bat : a script that run CMake to generate Visual Studio solution

genXCode.sh : a script that run CMake to generate XCode workspace.

bin : it is configure for all build files to be put in this bin file.

include : external libraries