#!/bin/sh

shaders=""

for shader in $(ls src/shaders)
do
    # check if shader is a directory
    if [ -d src/shaders/$shader ]
    then
        # check if it contains a callback.cc file
        if [ -f src/shaders/$shader/callback.cc ]
        then
        shaders="$shaders $shader"
        fi
    fi
done

if [ -z "$shaders" ]
then
    echo "No shaders were found, check that your shader is in the src/shaders directory and contains a callback.cc file."
    echo "aternatively you can create a new shader by running ./new_shader.sh"
    exit 1
fi


echo "if your shader is not listed, make sure it contains a callback.cc file"
echo "====================="
echo "Choose a shader:"

select shader in $shaders

do
    echo -n $shader > src/shaders/shader_to_run.txt
    cmake -B build
    cd build
    make
    ./shader
    break
done