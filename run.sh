#!/bin/sh

shaders=""

for shader in $(ls src/shaders)
do
    # check if shader is a directory
    if [ -d src/shaders/$shader ]
    then
        # check if it contains a main.cc file
        if [ -f src/shaders/$shader/main.cc ]
        then
        shaders="$shaders $shader"
        fi
    fi
done

if [ -z "$shaders" ]
then
    echo "No shaders were found, check that your shader is in the src/shaders directory and contains a main.cc file."
    echo "aternatively you can create a new shader by running ./new_shader.sh"
    exit 1
fi

if [ $# -eq 1 ]
then
    # check if shader exists
    if [ ! -d src/shaders/$1 ]
    then
        echo "Shader $1 does not exist"
        exit 1
    fi
    shader=$1
    echo -n $shader > src/shaders/shader_to_run.txt
    cmake -B build
    cd build
    make
    if [ $? -eq 0 ]
    then
        ./shader
    fi
    exit 0

elif [ $# -gt 1 ]
then
    echo "Too many arguments, please only specify one shader or none"
    exit 1
else
    echo "if your shader is not listed, make sure it contains a main.cc file"
    echo "====================="
    echo "Choose a shader:"

    select shader in $shaders
    do
        echo -n $shader > src/shaders/shader_to_run.txt
        cmake -B build
        cd build
        make
        if [ $? -eq 0 ]
        then
            ./shader
        fi
        break
    done
fi


