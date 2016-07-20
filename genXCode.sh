#!/bin/bash
Workspace_PATH=/Users/j/Documents/Xcode\ Workspace
Source_PATH="$Workspace_PATH"/CMakeFirstTry
GEN_PATH="$Source_PATH"/CMakeGen/Xcode
CMAKE_PATH="$Workspace_PATH"/CMakeApp/bin/cmake

if [[ ! -d "$Source_PATH"/CMakeGen ]]; then
	mkdir "$Source_PATH"/CMakeGen
fi
if [[ ! -d "$GEN_PATH" ]]; then
	mkdir "$GEN_PATH"
fi

cd "$GEN_PATH"
"$CMAKE_PATH" -G "Xcode" -DCMAKE_SOURCE_DIR="$GEN_PATH" -DCMAKE_BINARY_DIR="$GEN_PATH" -DCMAKE_INSTALL_PREFIX="$GEN_PATH" "$Source_PATH"