CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

PROJECT(GoldWriter)

FIND_PACKAGE(Geant4 REQUIRED ui_all vis_all)
IF(NOT Geant4_FOUND)
    MESSAGE(FATAL_ERROR "Geant4 not found!")
ENDIF(NOT Geant4_FOUND)

INCLUDE(${Geant4_USE_FILE})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
#  ${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
FILE(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

ADD_EXECUTABLE(BGMSC BGMSC.cc ${sources} ${headers})
TARGET_LINK_LIBRARIES(BGMSC ${Geant4_LIBRARIES})

set(BGMSC_SCRIPTS
    init_vis.mac
    PSF_-125.IAEAheader
    PSF_-125.IAEAphsp
)

foreach(_script ${BGMSC_SCRIPTS})
    configure_file(
        ${PROJECT_SOURCE_DIR}/${_script}
        ${PROJECT_BINARY_DIR}/${_script}
        COPYONLY)
endforeach()




