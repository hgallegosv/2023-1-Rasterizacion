#version 330 core

in vec4 normal;
in vec4 posicion;
//in vec3 colorFinal;

out vec4 FragColor;

void main() {
   vec4 colorLuz = vec4(1., 1., 1., 1.);
   vec4 posicionLuz = vec4(1., 1., 10., 1.0);

   vec4 color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   float kd = 0.8;

   // Compute the diffuse term.
   vec4 N = normalize( normal );
   vec4 L = normalize( posicionLuz - posicion );
   float NdotL = max( dot( N, L ), 0 );
   vec4 Diffuse =  NdotL * colorLuz * color;
   FragColor = Diffuse;
}