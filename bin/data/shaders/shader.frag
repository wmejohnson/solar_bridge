// fragment shader
#version 120
#define PI 3.14159265359
#define TWO_PI 6.28318530718

//variable setup
uniform float           u_time;
uniform vec2            u_resolution;
uniform vec2            u_mouse;

//random from shader book
float random (vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233)))*
                 43758.5453123 + u_time);
}

//main shader call
void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    
    vec3 rand = vec3(random(st));
    
    gl_FragColor = vec4(rand,0.05);
}

