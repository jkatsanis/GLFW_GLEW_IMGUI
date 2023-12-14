# Core/CMakeLists.txt

# Set the path to libraries
set(PATH_LIBRARIES ${CMAKE_SOURCE_DIR}/3D-Renderer/Source/Libs)

# Globbing source files
file(GLOB_RECURSE RENDERER_SOURCE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
)

# Define the library
add_library(${CORE_NAME} STATIC ${RENDERER_SOURCE_FILES})

# Link libraries
target_link_libraries(${CORE_NAME} PUBLIC
    ${PATH_LIBRARIES}/GLEW/glew32s.lib
    ${PATH_LIBRARIES}/GLFW/glfw3.lib
    opengl32.lib
    glu32.lib
)

target_compile_definitions(${CORE_NAME} PUBLIC GLEW_STATIC)

# Include directories
target_include_directories(${CORE_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/Libs
    ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

# Group source files in IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${RENDERER_SOURCE_FILES})

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT /NODEFAULTLIB:MSVCRT")
endif()
