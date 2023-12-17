# Editor/CMakeLists.txt

set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/3D-Renderer/Source/Libs)

file(GLOB_RECURSE APP_SOURCE
    "Source/*.cpp"
    "Source/*.h"
)

add_executable(${APPLICATON_NAME} ${APP_SOURCE})

# Link the 3D Renderer library(s)
target_link_libraries(${APPLICATON_NAME} PRIVATE
    3D-Renderer
)

include_directories(${CMAKE_SOURCE_DIR}/3D-Renderer/Source)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${APP_SOURCE})