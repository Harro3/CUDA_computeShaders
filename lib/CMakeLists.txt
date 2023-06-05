cmake_minimum_required(VERSION 3.21.2)

project(CUDA_computeShaders)


add_library(libCUDA_computeShaders SHARED
    "shader_frames.cc"
    "shader_functions.cc"
    "shader.cc"
)

set_target_properties(libCUDA_computeShaders PROPERTIES OUTPUT_NAME CUDA_computeShaders)
set_target_properties(libCUDA_computeShaders PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
    CUDA_SEPARABLE_COMPILATION ON
)

# link SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(libCUDA_computeShaders PUBLIC sfml-graphics)



target_compile_options(libCUDA_computeShaders PRIVATE -Wall -Wextra -Werror -pedantic)

target_include_directories(libCUDA_computeShaders PUBLIC "./")