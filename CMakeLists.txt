cmake_minimum_required(VERSION 3.21.2)

project(HarroShaderEngine)

# to build the library
add_subdirectory(lib)

file(READ src/shaders/shader_to_run.txt SHADER_PATH)

# to build the executable
add_executable(
    shader
    src/main.cc

    src/shaders/${SHADER_PATH}/callback.cc

    )

set_target_properties(shader PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS NO
)

target_compile_options(shader PRIVATE
    -Wall
    -Wextra
    -pedantic
    -Werror
   # -fsanitize=address
)

target_link_options(shader PRIVATE
   # -fsanitize=address
)

# to include the API headers
target_include_directories(shader PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/
)

target_link_libraries(shader PRIVATE libHarroShaderEngine)