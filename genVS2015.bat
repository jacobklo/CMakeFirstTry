set Workspace_PATH=D:\workspace\
set Source_PATH=%Workspace_PATH%CMakeFirstTry\
set GEN_PATH=%Source_PATH%CMakeGen\vs2015\
if not exist %Source_PATH%CMakeGen\ mkdir %Source_PATH%CMakeGen\
if not exist %GEN_PATH% mkdir %GEN_PATH%

cd %GEN_PATH%
%Workspace_PATH%CMakeApp\bin\cmake.exe -G "Visual Studio 14 2015" -DCMAKE_SOURCE_DIR=%GEN_PATH% -DCMAKE_BINARY_DIR=%GEN_PATH% -DCMAKE_INSTALL_PREFIX=%GEN_PATH% %Source_PATH%
