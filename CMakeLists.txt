### Require an up-to-date cmake ###
cmake_minimum_required(VERSION 3.10.0)
project(libpirates)

### Find pythonic libs ###
find_package(PythonLibs)
if (NOT PYTHONLIBS_FOUND)
	message(FATAL_ERROR "Python libs could not be located!")
endif()

### Find the python interpreter ###
find_package(PythonInterp)
if (NOT PYTHONINTERP_FOUND)
	message(FATAL_ERROR "Python interpreter could not be located!")
endif()

### Make sure we're using Python 2 ###
if(PYTHON_VERSION_MAJOR EQUAL 2)
    set(PYTHON2_EXECUTABLE "${PYTHON_EXECUTABLE}")
else()
    set(PYTHON2_EXECUTABLE python2)
endif()

### Set the Panda3D directory ###
if (WIN32)
	set(PANDA_DIR "C:\\Panda3D-1.9.4" CACHE STRING "Panda3D directory.")
endif()

### Execute interrogate and generate Python bindings ###
### Panda's equivalent of swig (supposed to be faster) ###
execute_process(COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}")

### Define core files ###
set(CORE_FILES
	src/core/config_libpirates.h
	src/core/config_libpirates.cxx
)

### Define seapatch files ###
set(SEAPATCH_FILES
	src/seapatch/seaPatchNode.h
	#src/seapatch/seaPatchNode.I
	src/seapatch/seaPatchNode.cxx
)

### Define interrogate files ###
set(IGATE_FILES
    src/core_igate.cxx
    src/seapatch_igate.cxx
    src/libpirates_module.cxx
)

### Include all of our program directories ###
include_directories(${CMAKE_SOURCE_DIR}/src/core)
include_directories(${CMAKE_SOURCE_DIR}/src/seapatch)

### Include all of our lib directories ###
include_directories(${PANDA_DIR}/include)
include_directories(${PYTHON_INCLUDE_DIR})

### Link our Panda3D libs ###
link_directories(${PANDA_DIR}/lib)

set(LIBPFX "")
if(WIN32)
    set(LIBPFX "lib")
    add_definitions(/wd4275)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    message(STATUS "GCC Version: ${GCC_VERSION}")
    if(GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        add_definitions(-std=c++11) # Enable the new C++ standard
    else()
        add_definitions(-std=c++0x) # Enable the new C++ standard
    endif()
endif()

add_definitions(-DBUILDING_LIBPIRATES)

### Define all of our Panda3D libs ###
set(PANDA_LIBS
	${LIBPFX}p3framework
	${LIBPFX}panda
	${LIBPFX}pandafx
	${LIBPFX}pandaexpress
	${LIBPFX}p3dtool
	${LIBPFX}p3dtoolconfig
	${LIBPFX}p3direct
	${LIBPFX}p3pandatoolbase
)

# Add p3pandatoolbase, if it exists
find_library(HAVE_P3PANDATOOLBASE
    ${LIBPFX}p3pandatoolbase
    HINTS ${PANDA_DIR}/lib)
				 
if (HAVE_P3PANDATOOLBASE)
    message(STATUS "libp3pandatoolbase found")
    LIST(APPEND PANDA_LIBS ${LIBPFX}p3pandatoolbase)
else()
    message(STATUS "libp3pandatoolbase not found")
endif()
	
### Add the libpirates library ###
add_library(libpirates SHARED
	${CORE_FILES}
	${SEAPATCH_FILES}
	${IGATE_FILES}
)
		
SET_TARGET_PROPERTIES(libpirates PROPERTIES SUFFIX ".pyd")

target_link_libraries(libpirates ${PANDA_LIBS} ${PYTHON_LIBRARY})
		
add_custom_command(TARGET libpirates
					PRE_BUILD
					COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
					COMMENT "Interrogate")

### Setup source groups and defines for configurables ###
source_group("core" FILES ${CORE_FILES})
source_group("seapatch" FILES ${SEAPATCH_FILES})
source_group("interrogate_files" FILES ${IGATE_FILES})