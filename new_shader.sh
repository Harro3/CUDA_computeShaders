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

if [ $# -ge 1 ]
then
    shader_name=$1
else
    echo -n "Enter the name of your new shader: "
    read shader_name
    fi

if [ -z "$shader_name" ]
then
    echo "No shader name was entered, exiting..."
    exit 1
fi

# check if shader already exists
for shader in $shaders
do
    if [ $shader == $shader_name ]
    then
        echo "A shader with that name already exists, exiting..."
        exit 1
    fi
done

mkdir src/shaders/$shader_name
touch src/shaders/$shader_name/main.cc

cp src/shaders/template.cc src/shaders/$shader_name/main.cc