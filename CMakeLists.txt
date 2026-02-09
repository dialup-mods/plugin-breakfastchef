cmake_minimum_required(VERSION 4.0)

set(DIALUP_INSTALL_DIR "$ENV{LOCALAPPDATA}/DialUp")
include("${DIALUP_INSTALL_DIR}/build-tools/PreProject.cmake")
include("${DIALUP_INSTALL_DIR}/build-tools/GameBinaryDir.cmake")

project(BreakfastChef VERSION 1.0 LANGUAGES CXX)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
)

set(INCLUDES
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${DIALUP_INSTALL_DIR}/include
    ${DIALUP_INSTALL_DIR}/include/v1
    ${DIALUP_INSTALL_DIR}/include/external
    ${DIALUP_INSTALL_DIR}/sdk-plugin/include
    ${DIALUP_INSTALL_DIR}/plugin/Toaster/include
)

include("${DIALUP_INSTALL_DIR}/build-tools/Plugin.cmake")

dialup_setup_module(${PROJECT_NAME}
    SOURCES ${SOURCES}
    INCLUDES ${INCLUDES}
    DESTINATION "plugin/${PROJECT_NAME}"
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/build/${PROJECT_NAME}.dll
    DESTINATION ${GAME_BINARY_PATH})

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/build/${PROJECT_NAME}.pdb
    DESTINATION ${GAME_BINARY_PATH})

find_package(DialUp REQUIRED PATHS ${DIALUP_INSTALL_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE DialUp::DialUp)

find_package(Toaster REQUIRED PATHS ${DIALUP_INSTALL_DIR}/plugin/Toaster)
target_link_libraries(${PROJECT_NAME} PRIVATE Toaster::Toaster)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${INCLUDES}
    PUBLIC
        $<INSTALL_INTERFACE:include>
)

target_compile_definitions(${PROJECT_NAME} PRIVATE TOAST_BUILD)

include("${DIALUP_INSTALL_DIR}/build-tools/PostProject.cmake")
