#version 330 core

in vec2 pass_textureCoords;
in vec3 pass_normalCoords;
in vec3 lightPos;
in vec3 toCameraVector;

out vec4 color;

uniform sampler2D u_texture;
uniform int u_textureType;
uniform vec4 u_color;

vec4 lightColor = vec4(1.0, 1.0, 1.0, 1.0);
float ambient = 0.1;

vec4 sunColor = vec4(1.0, 1.0, 1.0, 1.0);

float reflectivity = 0.5;
int shineDamper = 32;

void main(){
    vec3 normal = normalize(pass_normalCoords);
    vec3 lightDirection = normalize(lightPos);

    float diffuse = max(dot(normal, lightDirection), 0.0);
    diffuse = max(diffuse, ambient);

    vec3 viewDirection = normalize(toCameraVector);
    vec3 reflectDirection = reflect(-lightDirection, normal);
    float specular = reflectivity * pow(max(dot(viewDirection, reflectDirection), 0.0), shineDamper);

    vec4 light = (diffuse + specular) * lightColor * u_color;

   if(u_textureType != 0) {
        color = light * texture(u_texture, pass_textureCoords);
   } else {
        color = light;
   }
}