#--------------------------------------------
# NO NEED MODIFY
# Add all subdirectories to this project,
# which is getting from this directories name
#--------------------------------------------

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})


# Add another sub-Projects, if needed
#------------------------------------
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

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

# Can choose to use HEADER_DIRECTORIES or SUBDIRLIST macro
###--- NOT USING ---### SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
HEADER_DIRECTORIES (SUBDIRS )
Set (allFiles "")
string ( LENGTH ${CMAKE_CURRENT_SOURCE_DIR} currentSourceSize)

FOREACH(subdir ${SUBDIRS})
	# Add header files and source files here
 	#---------------------------------------
 	string ( LENGTH ${subdir} currentSubDirSize)
 	string ( SUBSTRING ${subdir} ${currentSourceSize} ${currentSubDirSize} subDirRelative)
 	message ( ${subDirRelative})
	file (GLOB allHeaders "${subdir}/*.h" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allHeaders})
	List (APPEND allFiles ${allHeaders})
	file (GLOB allCs "${subdir}/*.c" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allCs})
	List (APPEND allFiles ${allCs})
	file (GLOB allCPPs "${subdir}/*.cpp" LIST_DIRECTORIES=true )
	SOURCE_GROUP ( ${subDirRelative} FILES ${allCPPs})
	List (APPEND allFiles ${allCPPs})
	

	## Don't need for add subdirectory because we don't need to create another subprojects
	##add_subdirectory(${subdir})
ENDFOREACH()



# Create Static Library
#----------------------
add_library ("${PROJECT_NAME}_STATIC" STATIC ${allFiles})

install(TARGETS "${PROJECT_NAME}_STATIC"
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib/static)

# Create Shared Library
#----------------------
add_library ("${PROJECT_NAME}_SHARED" SHARED ${allFiles})

install(TARGETS "${PROJECT_NAME}_SHARED"
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION libs
		ARCHIVE DESTINATION libs/shared)


#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------
