project(static_lib)

# add include directory
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# get source list of the directory
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
# message(${SRC_LIST})


# add source to this project's library dll
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})