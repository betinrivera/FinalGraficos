#pragma once

#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <vector>
#include "Vertice.h"
#include "Shader.h"

using namespace std;

class Modelo {
public:
	vector<Vertice> vertices;
	mat4 modelo;
	mat4 vista;
	mat4 proyeccion;

	Shader *shader;
	GLuint vertexArrayID;
	GLuint bufferID;
	GLuint modeloID;
	GLuint vistaID;
	GLuint proyeccionID;
	GLuint texturaID;
	GLuint samplerImagenID;

	GLuint uvBufferID;
	vector<vec2> mapaUV;

	Modelo();
	void inicializarVertexArray(GLuint posicionID, GLuint colorID, GLuint modeloID, GLuint vistaID, GLuint proyeccionID, GLuint uvID, GLuint samplerImagenID, GLuint texturaID);
	void dibujar(GLenum modoDibujo);
	
};
