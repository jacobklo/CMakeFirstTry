CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

#--------------------------------------------
# NO NEED MODIFY
# Add all subdirectories to this project,
# which is getting from this directories name
#--------------------------------------------

# About this project
#-------------------
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------

SET(VERSION_MAJOR “0”)
SET(VERSION_MINOR “1”)
SET(VERSION_PATCH “0”)
SET(VERSION “${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}”)

# Set env
#--------
add_definitions(-DCHECK_DEFINED)

# For #include to work in Visual studio/IDE
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/JLib)
include_directories(${PROJECT_SOURCE_DIR}/LoadCLib)
include_directories(${PROJECT_SOURCE_DIR}/TestJLib)

link_directories(${PROJECT_SOURCE_DIR}/external/lib)

# Set all build output at ${PROJECT_SOURCE_DIR}/bin. So it is universal
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(ANDROID_STANDALONE_TOOLCHAIN C:\ProgramData\Microsoft\AndroidNDK\android-ndk-r12)

# Add subfolders, has to manual add for each sub-project
#---------------
add_subdirectory(JLib)
add_subdirectory(LoadCLib)
add_subdirectory(RunJLib)
add_subdirectory(TestJLib)
