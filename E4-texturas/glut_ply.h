#ifndef GLUT_PLY_H
#define GLUT_PLY_H
/*
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
*/

//#include "Triangle.h"
//#include <glew.h>
//#include <freeglut/freeglut.h>
#include <vector>
//#include "vmath.h"

class Model_PLY {
public:
	Model_PLY();

    int		Load(char *filename);
//    int		Load(char *filename, float scaleFactor);
//    void	Draw();
//    float*	calculateNormal(float *coord1, float *coord2, float *coord3);
//    void	transform(Matrix4f transformation);

//    float	*Faces_Triangles;
    float	*Vertices;
    float	*Normales;
    unsigned int     *Indices;

    int     cantVertices;
    int     cantIndices;

//    int		TotalConnectedTriangles;
//    int		TotalConnectedPoints;
//    int		TotalFaces;

//    float	scaleFactor;
//	vector<Triangle*> *triangles;

	// Position min and max for AABB
//	Vector3f posMin, posMax;
};

#endif
