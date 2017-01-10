cmake_minimum_required (VERSION 2.6)
project (Totoriool)

set (Totoriool_VERSION_MAJOR 1)
set (Totoriool_VERSION_MINOR 0)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

option (USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
	include_directories ("${PROJECT_SOURCE_DIR}/mathfunc")
	add_subdirectory (mathfunc)
	set (EXTRA_LIBS ${EXTRA_LIBS} mathfunc)
endif (USE_MYMATH)

configure_file (
	"${PROJECT_SOURCE_DIR}/totoriolConfig.h.in"
	"${PROJECT_BINARY_DIR}/totoriolConfig.h"
	)

include_directories (${PROJECT_BINARY_DIR})

add_executable (Totoriool totoriol.cpp)
target_link_libraries (Totoriool ${EXTRA_LIBS})
