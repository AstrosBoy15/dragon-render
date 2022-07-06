#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoords;
layout(location = 2) in vec3 normalCoords;

out vec2 pass_textureCoords;
out vec3 pass_normalCoords;
out vec3 lightPos;
out vec3 toCameraVector;

vec3 sunPosition = vec3(5, 3, 0);

uniform mat4 u_m;
uniform mat4 u_v;
uniform mat4 u_p;

void main(){
    gl_Position = u_p * u_v * u_m * vec4(position, 1.0);

    vec3 worldPos = (u_m * vec4(position, 1.0)).xyz;
    toCameraVector = (inverse(u_v) * vec4(0.0, 0.0, 0.0, 1.0)).xyz - worldPos;
    lightPos = sunPosition - worldPos;

    pass_textureCoords = textureCoords;
    pass_normalCoords = (u_m * vec4(normalCoords, 0)).xyz;
}