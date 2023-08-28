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
touch src/shaders/$shader_name/callback.cc

template="#include \"../config.hh\" \n\n\
#include \"shader.hh\" \n\n\
void callback(int x, int y, double seconds, color &c) \n\
{ \n\
    // your code here \n\
    // x and y are the pixel coordinates \n\
    // seconds is the number of seconds since the program started \n\
    // c is the color of the pixel \n\n\
    // example: \n\
    c.r = x / 512.0; \n\
    c.g = y / 512.0; \n\
    c.b = seconds / 10.0; \n\
} \n"

echo -e $template > src/shaders/$shader_name/callback.cc