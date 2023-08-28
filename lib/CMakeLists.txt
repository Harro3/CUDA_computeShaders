cmake_minimum_required(VERSION 3.21.2)

project(HarroShaderEngine)


add_library(libHarroShaderEngine SHARED
    "shader_frames.cc"
    "shader_functions.cc"
    "shader.cc"
)

set_target_properties(libHarroShaderEngine PROPERTIES OUTPUT_NAME HarroShaderEngine)
set_target_properties(libHarroShaderEngine PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    CUDA_SEPARABLE_COMPILATION ON
)

# link SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(libHarroShaderEngine PUBLIC sfml-graphics)



target_compile_options(libHarroShaderEngine PRIVATE -Wall -Wextra -Werror -pedantic)

target_include_directories(libHarroShaderEngine PUBLIC "./")