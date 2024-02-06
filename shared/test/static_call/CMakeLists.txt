cmake_minimum_required (VERSION 3.8)

project ("shared_static_call_test")

# message(STATUS "CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
	${CMAKE_SOURCE_DIR}/../extern/googletest/include
	${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

link_directories(
    # ${CMAKE_CURRENT_SOURCE_DIR}/../../src/${CMAKE_BUILD_TYPE}
	${GOOGLE_TEST_LIB_PATH}
)

# get source list of the directory
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}  SRC_LIST)
# message(${SRC_LIST})

# add source to this project's library
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PUBLIC
	gtest
	gtest_main
    shared_library
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

FILE(GLOB TEST_DLL CONFIGURE_DEPENDS 
    ${PROJECT_BINARY_DIR}/../../src/${CMAKE_BUILD_TYPE}/*.dll
)
add_custom_command (TARGET ${PROJECT_NAME}
    PRE_LINK
    VERBATIM 
    COMMAND_EXPAND_LISTS
    COMMAND ${CMAKE_COMMAND} -E 
        make_directory "${PROJECT_BINARY_DIR}/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/" 
	COMMAND ${CMAKE_COMMAND} -E 
        copy_if_different  
            "$<$<CONFIG:Release>:${TEST_DLL}>"  
            "$<$<CONFIG:Debug>:${TEST_DLL}>" 
            "${PROJECT_BINARY_DIR}/$<$<CONFIG:Release>:Release>$<$<CONFIG:Debug>:Debug>/"
)