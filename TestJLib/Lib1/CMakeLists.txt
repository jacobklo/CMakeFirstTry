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

# Add another sub-Projects, if needed
#------------------------------------
## From : http://www.vtk.org/Wiki/CMake/Examples#Message
MACRO(HEADER_DIRECTORIES return_list)
  FILE(GLOB_RECURSE new_list *.h)
  SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()


HEADER_DIRECTORIES (SUBDIRS )
Set (allFiles "")
string ( LENGTH ${CMAKE_CURRENT_SOURCE_DIR} currentSourceSize)

FOREACH(subdir ${SUBDIRS})
	# Add header files and source files here
 	#---------------------------------------
 	string ( LENGTH ${subdir} currentSubDirSize)
 	string ( SUBSTRING ${subdir} ${currentSourceSize} ${currentSubDirSize} subDirRelative)
 	file (GLOB allHeaders "${subdir}/*.h" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allHeaders})
	List (APPEND allFiles ${allHeaders})
	file (GLOB allCs "${subdir}/*.c" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allCs})
	List (APPEND allFiles ${allCs})
	file (GLOB allCPPs "${subdir}/*.cpp" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allCPPs})
	List (APPEND allFiles ${allCPPs})
ENDFOREACH()


# Create Exe
#----------------------
add_executable (${PROJECT_NAME}_test ${allFiles} )

target_link_libraries(${PROJECT_NAME}_test JLib_STATIC)

#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------
