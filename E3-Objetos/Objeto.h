//
// Created by hgallegos on 5/10/2022.
//

#ifndef LEARNOPENGL_OBJETO_H
#define LEARNOPENGL_OBJETO_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "shader_m.h"
#include "BoundingVolume.h"
using namespace std;
using namespace glm;

class Objeto {
public:
    vector<vec3> positions;
    vector<vec3> normals;
    vector<vec2> textureCoords;
    vector<GLuint> indices;
    GLuint indices_size;
    float v0, x0, y0, a0, xt, yt;
    float tiempo_inicial;
    GLuint vao;
    mat4 model;
    bool visible=true;
    BoundingSphere *bs;
    GLint POSITION_ATTRIBUTE=0, NORMAL_ATTRIBUTE=1, TEXCOORD0_ATTRIBUTE=8;
    virtual GLuint setup()=0;
    virtual void display(Shader &sh)=0;
    virtual void actualizarPosicion(float tiempo)=0;
    virtual void actualizarBS() = 0;
};

class Esfera:public Objeto{
public:
    vec3 centro;
    float radius;
    int slices, stacks;
    Esfera() {
        centro = vec3(0.0);
    }
    Esfera(vec3 _centro) {
        centro = _centro;
    }
    Esfera(vec3 _centro, float _radius, int _slices, int _stacks) {
        centro = _centro;
        radius = _radius;
        slices = _slices;
        stacks = _stacks;
    }
    GLuint setup();

    void display(Shader &sh);
    void actualizarPosicion(float tiempo);
    void actualizarBS();
};

class Plano: public Objeto{
public:
    vec3 normal;
    float d;
    Plano(vec3 _normal, float _d){ normal=_normal; d=_d; }
    void display(Shader &sh){}
    void actualizarPosicion(float tiempo){}
    void actualizarBS() {}
};

#endif //LEARNOPENGL_OBJETO_H
