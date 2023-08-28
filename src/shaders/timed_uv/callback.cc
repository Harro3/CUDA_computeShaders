#include "../config.hh" 

#include "shader.hh" 

void callback(int x, int y, double seconds, color &c) 
{ 
 // your code here 
 // x and y are the pixel coordinates 
 // seconds is the number of seconds since the program started 
 // c is the color of the pixel 

 // example: 
 c.r = x / 512.0; 
 c.g = y / 512.0; 
 c.b = seconds / 10.0; 
} 

