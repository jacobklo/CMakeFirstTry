# --- Transitional CMakeLists --- Adding all subProjects
#--------------------------------------------
# NO NEED MODIFY
# Add all subdirectories to this project,
# which is getting from this directories name
#--------------------------------------------

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

SUBDIRLIST ( subdirs ${CMAKE_CURRENT_SOURCE_DIR})

FOREACH( subdir ${subdirs})
  ##project(${subdir})
  add_subdirectory(${subdir})
ENDFOREACH()

#--------------------------------------------
# -- END -- NO NEED MODIFY
#--------------------------------------------
