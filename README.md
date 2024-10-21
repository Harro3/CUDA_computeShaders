# CUDA_computeShaders
An attempt at implementing shaders in c++ with cuda (For now CUDA is not implemented, it is just basic multithreading)

# Usage

To use the program, you need to either select one of the example shaders, or create a new one with `./new-shader.sh <shader-name>`
Then go under `src/shaders/` to edit the created shader, you can use the examples to see how the very simple API works.

Then execute `./run.sh` and when prompted, select the desired shader.
