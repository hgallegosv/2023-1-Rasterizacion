#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 matrix_model;
uniform mat4 matrix_view;
uniform mat4 matrix_projection;

out vec4 normal;
out vec4 posicion;
//out vec3 colorFinal;

void main()
{
   mat4 mvp = matrix_projection * matrix_view * matrix_model;

   gl_Position = mvp * vec4(aPos, 1.0);
   posicion = matrix_model * vec4(aPos, 1.0);
   normal = matrix_model * vec4(aNormal, 0.0);

   // iluminacion difusa en vertex shader
   //vec3 posicionLuz = vec3(1., 1., -10.);
   //vec3 colorLuz = vec3(1., 1., 1.);
   //vec4 color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //float kd = 0.8;
   //float diff = max(0.0, dot(normalize(posicionLuz - aPos), aNormal));
   //colorFinal = color.rgb * colorLuz * kd * diff;

}