#include "glut_ply.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

Model_PLY::Model_PLY() {
	/*this->TotalConnectedTriangles = 0;
    this->TotalConnectedPoints = 0;
    this->Faces_Triangles = NULL;
	this->Normals = NULL;
	this->scaleFactor = 1.0;
    this->TotalFaces = 0;
    this->Vertex_Buffer = NULL;
	triangles = new vector<Triangle*>;
	posMin = posMax = Vector3f(0.0f, 0.0f, 0.0f);*/
}

/*
float* Model_PLY::calculateNormal(float *coord1, float *coord2, float *coord3)
{
    // calculate Vector1 and Vector2
    float va[3], vb[3], vr[3], val;
    va[0] = coord1[0] - coord2[0];
    va[1] = coord1[1] - coord2[1];
    va[2] = coord1[2] - coord2[2];

    vb[0] = coord1[0] - coord3[0];
    vb[1] = coord1[1] - coord3[1];
    vb[2] = coord1[2] - coord3[2];

    // cross product
    vr[0] = va[1] * vb[2] - vb[1] * va[2];
    vr[1] = vb[0] * va[2] - va[0] * vb[2];
    vr[2] = va[0] * vb[1] - vb[0] * va[1];

    // normalization factor
    val = sqrt(vr[0] * vr[0] + vr[1] * vr[1] + vr[2] * vr[2]);

    float *norm = new float[3];
    norm[0] = -vr[0] / val;
    norm[1] = -vr[1] / val;
    norm[2] = -vr[2] / val;

    return norm;
}*/

int Model_PLY::Load(char* filename) {
//    float sf = 1.0;
//    return this->Load(filename, sf);
//}

//int Model_PLY::Load(char* filename, float sf) {
//    this->TotalConnectedTriangles	= 0;
//    this->TotalConnectedPoints		= 0;

    char* pch = strstr(filename, ".ply");

    if (pch != NULL) {
        FILE* file = fopen(filename, "r");

        /*fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);

        try {
            Vertices = (float*) malloc(ftell(file));
        } catch (char*) {
            return -1;
        }
        if (Vertices == NULL)
            return -1;
        fseek(file, 0, SEEK_SET);*/

        //Faces_Triangles = (float*) malloc(fileSize * sizeof(float));
        //Normales = (float*) malloc(fileSize * sizeof(float));
        //Indices  = (float*) malloc(fileSize * sizeof(float));

        if (file) {
            int		i = 0;
            //int		temp = 0;
            //int		quads_index = 0;
            //int		triangle_index = 0;
            int		normal_index = 0;
            char	buffer[1000];

            fgets(buffer, 1000, file);			// ply

            // READ HEADER
            // -----------------
            // Find number of vertexes
            while (strncmp("element vertex", buffer, strlen("element vertex")) != 0) {
                fgets(buffer, 300, file);			// format
            }
            strcpy(buffer, buffer + strlen("element vertex"));
            sscanf(buffer, "%i", &this->cantVertices);
            Vertices = (float*) malloc(cantVertices * 3 * sizeof(float));
            Normales = (float*) malloc(cantVertices * 3 * sizeof(float));

            // Find number of faces
            fseek(file, 0, SEEK_SET);
            while (strncmp("element face", buffer, strlen("element face")) != 0) {
                fgets(buffer, 300, file);			// format
            }
            strcpy(buffer, buffer + strlen("element face"));
            sscanf(buffer, "%i", &this->cantIndices);
            Indices = (unsigned int*) malloc(cantIndices * 3 * sizeof(unsigned int));

            // go to end_header
            while (strncmp("end_header", buffer, strlen("end_header")) != 0) {
                fgets(buffer, 300, file);			// format
            }

            //----------------------
            // read verteces
            i = 0;
            int iterator;
            for (iterator = 0; iterator < this->cantVertices; iterator++) {
                fgets(buffer, 300, file);

                sscanf(buffer, "%f %f %f %f %f %f",
                       &Vertices[i], &Vertices[i + 1], &Vertices[i + 2],
                       &Normales[i], &Normales[i + 1], &Normales[i + 2]);
                //std::cout << Vertices[i] << "\t" << Vertices[i+1] << "\t" << Vertices[i+2] << std::endl;

				//Vertices[i]	 *= sf;
                //Vertices[i + 1] *= sf;
                //Vertices[i + 2] *= sf;
                i += 3;
            }

            // read faces
            i = 0;
            for (iterator = 0; iterator < this->cantIndices; iterator++) {
                fgets(buffer, 300, file);

                if (buffer[0] == '3') {
                    int idx1 = 0, idx2 = 0, idx3 = 0;
                    //sscanf(buffer,"%i%i%i\n", vertex1,vertex2,vertex3 );
                    buffer[0] = ' ';
                    sscanf(buffer, "%i %i %i", &Indices[i], &Indices[i+1], &Indices[i+2]);
                    //std::cout << Indices[i] << "\t" << Indices[i+1] << "\t" << Indices[i+2] << std::endl;

                    /*vertex1 -= 1;
                     vertex2 -= 1;
                     vertex3 -= 1;
                     */
                    //  vertex == punt van vertex lijst
                    // vertex_buffer -> xyz xyz xyz xyz
                    //printf("%f %f %f ", Vertex_Buffer[3*vertex1], Vertex_Buffer[3*vertex1+1], Vertex_Buffer[3*vertex1+2]);
                    /*Faces_Triangles[triangle_index]		= Vertex_Buffer[3 * vertex1];
                    Faces_Triangles[triangle_index + 1] = Vertex_Buffer[3 * vertex1 + 1];
                    Faces_Triangles[triangle_index + 2] = Vertex_Buffer[3 * vertex1 + 2];
                    Faces_Triangles[triangle_index + 3] = Vertex_Buffer[3 * vertex2];
                    Faces_Triangles[triangle_index + 4] = Vertex_Buffer[3 * vertex2 + 1];
                    Faces_Triangles[triangle_index + 5] = Vertex_Buffer[3 * vertex2 + 2];
                    Faces_Triangles[triangle_index + 6] = Vertex_Buffer[3 * vertex3];
                    Faces_Triangles[triangle_index + 7] = Vertex_Buffer[3 * vertex3 + 1];
                    Faces_Triangles[triangle_index + 8] = Vertex_Buffer[3 * vertex3 + 2];

                    triangles->push_back(
                            new Triangle(
                                    Vector3f(Faces_Triangles[triangle_index],
											 Faces_Triangles[triangle_index + 1],
											 Faces_Triangles[triangle_index + 2]),
                                    Vector3f(Faces_Triangles[triangle_index + 3],
                                             Faces_Triangles[triangle_index + 4],
                                             Faces_Triangles[triangle_index + 5]),
                                    Vector3f(Faces_Triangles[triangle_index + 6],
                                             Faces_Triangles[triangle_index + 7],
                                             Faces_Triangles[triangle_index + 8])));

                    float coord1[3] = { Faces_Triangles[triangle_index], 
										Faces_Triangles[triangle_index + 1],
										Faces_Triangles[triangle_index + 2] };
                    float coord2[3] = { Faces_Triangles[triangle_index + 3], 
										Faces_Triangles[triangle_index + 4],
										Faces_Triangles[triangle_index + 5] };
                    float coord3[3] = { Faces_Triangles[triangle_index + 6], 
										Faces_Triangles[triangle_index + 7],
										Faces_Triangles[triangle_index + 8] };
                    float *norm = this->calculateNormal(coord1, coord2, coord3);          

                    Normals[normal_index] = norm[0];
                    Normals[normal_index + 1] = norm[1];
                    Normals[normal_index + 2] = norm[2];
                    Normals[normal_index + 3] = norm[0];
                    Normals[normal_index + 4] = norm[1];
                    Normals[normal_index + 5] = norm[2];
                    Normals[normal_index + 6] = norm[0];
                    Normals[normal_index + 7] = norm[1];
                    Normals[normal_index + 8] = norm[2];

                    normal_index += 9;

                    triangle_index += 9;
                    TotalConnectedTriangles += 3;

					// Position Min and Max
					posMin.x = min( min(posMin.x, coord1[0]), min(coord2[0], coord3[0]) );
					posMin.y = min( min(posMin.y, coord1[1]), min(coord2[1], coord3[1]) );
					posMin.z = min( min(posMin.z, coord1[2]), min(coord2[2], coord3[2]) );

					posMax.x = max( max(posMax.x, coord1[0]), max(coord2[0], coord3[0]) );
					posMax.y = max( max(posMax.y, coord1[1]), max(coord2[1], coord3[1]) );
					posMax.z = max( max(posMax.z, coord1[2]), max(coord2[2], coord3[2]) );*/
                }

                i += 3;
            }
            fclose(file);
            printf("Finish!!\n");
        } else {
            printf("File can't be opened\n");
        }
    } else {
        printf("File does not have a .PLY extension. ");
    }
    return 0;
}
/*
void Model_PLY::Draw() {
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, Faces_Triangles);
    glNormalPointer(GL_FLOAT, 0, Normals);
    glDrawArrays(GL_TRIANGLES, 0, TotalConnectedTriangles);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void Model_PLY::transform(Matrix4f transformation) {
    int i = 0;
    int iterator;
    for (iterator = 0; iterator < this->TotalConnectedPoints; iterator++) {
        Vector4f d(Vertex_Buffer[i], Vertex_Buffer[i + 1], Vertex_Buffer[i + 2], 1.0);
        d = transformation * d;
        Vertex_Buffer[i] = d[0];
        Vertex_Buffer[i + 1] = d[1];
        Vertex_Buffer[i + 2] = d[2];
        i += 3;
    }
    i = 0;
    int triangle_index = 0;
    for (iterator = 0; iterator < this->TotalFaces; iterator++)
    {
        Vector4f d(Faces_Triangles[triangle_index], Faces_Triangles[triangle_index + 1], Faces_Triangles[triangle_index + 2], 1.0);
        d = transformation * d;
        Faces_Triangles[triangle_index] = d[0];
        Faces_Triangles[triangle_index + 1] = d[1];
        Faces_Triangles[triangle_index + 2] = d[2];

        d = Vector4f(Faces_Triangles[triangle_index + 3], Faces_Triangles[triangle_index + 4], Faces_Triangles[triangle_index + 5], 1.0);
        d = transformation * d;
        Faces_Triangles[triangle_index + 3] = d[0];
        Faces_Triangles[triangle_index + 4] = d[1];
        Faces_Triangles[triangle_index + 5] = d[2];

        d = Vector4f(Faces_Triangles[triangle_index + 6], Faces_Triangles[triangle_index + 7], Faces_Triangles[triangle_index + 8], 1.0);
        d = transformation * d;
        Faces_Triangles[triangle_index + 6] = d[0];
        Faces_Triangles[triangle_index + 7] = d[1];
        Faces_Triangles[triangle_index + 8] = d[2];
        triangle_index += 9;
    }
    i = 0;
    for (i = 0; i < int(triangles->size()); i++)
    {
        Vector4f d((*triangles)[i]->v[0].x, (*triangles)[i]->v[0].y, (*triangles)[i]->v[0].z, 1.0);
        d = transformation * d;
        (*triangles)[i]->v[0] = Vector3d(d[0], d[1], d[2]);

        d = Vector4f((*triangles)[i]->v[1].x, (*triangles)[i]->v[1].y, (*triangles)[i]->v[1].z, 1.0);
                d = transformation * d;
        (*triangles)[i]->v[1] = Vector3d(d[0], d[1], d[2]);

        d = Vector4f((*triangles)[i]->v[2].x, (*triangles)[i]->v[2].y, (*triangles)[i]->v[2].z, 1.0);
                d = transformation * d;
        (*triangles)[i]->v[2] = Vector3d(d[0], d[1], d[2]);
    }
}
*/
