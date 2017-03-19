// fragment shader
#version 150

// this is how we receive the texture
uniform sampler2DRect tex0;
in vec2 tc;

out vec4 outputColor;
uniform vec2 u_resolution;

float circle(in vec2 _st, in float _radius){
    vec2 dist = _st-vec2(0.5);
    return 1.-smoothstep(_radius-(_radius*0.4),_radius-(_radius*0.45),dot(dist,dist)*2);
}

void main()
{
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    
    //texture input & chromatic abberation
    vec4 texCol = texture(tex0, vec2(tc.x, tc.y));
    vec4 texCol2 = texture(tex0, vec2(tc.x+10, tc.y));
    vec4 abCol = vec4(texCol.r, texCol2.g, texCol2.b, 1.0);
    
    //dots
    st *= 150;
    st = fract(st);
    float cirCol = circle(st, 0.1);
    
    vec4 outCol = abCol * cirCol;
    outputColor = outCol;
}
