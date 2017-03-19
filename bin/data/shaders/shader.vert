// vertex shader

#version 120

uniform mat4 modelViewProjectionMatrix;

void main(){
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

