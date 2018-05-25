// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"


#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Nave.h"
#include "Tacoma.h"

using namespace std;

GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

GLuint coordenadaUVID;
GLuint samplerImagenID;
GLuint texturaTacomaID;
GLuint texturaPacmanID;
GLuint texturaUnoID;
GLuint texturaDosID;

mat4 vista;
mat4 proyeccion;

Modelo *cuadrado;
Modelo *fruta;
Modelo *hoja;
Tacoma *tacoma;

Shader *shader;
//Declaración de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

vec3 posicionCamara;

double tiempoAnterior;

void actualizarVista() {
	vista = lookAt(posicionCamara, //Posicion de la cámara
		vec3(0.0f, 0.0f, 0.0f),				//Posición del objetivo
		vec3(0.0f, 1.0f, 0.0f));			//Vector hacia arriba (rotación cámara)
}

void inicializarProyeccion() {
	proyeccion =
		perspective(45.0f, //Campo de visión (FoV)
			ancho / alto, //Relación de aspecto (Aspect ratio)
			0.1f, //Near clipping (Desde donde renderea)
			150.0f); //Far clipping (Hasta donde renderea)
}

float bordeX = 10.0f;
float bordeY = 15.0f;

void checarColisiones() {

	//Si el pacman pega con la pared izquierda o la pared derecha, el juego se quita
	//Si el pacman pega con la pared de arriba o abajo, el juego se quita

	if (tacoma->coordenadas.x + 2.0 >= 15.0f / 0.8f ||
		tacoma->coordenadas.x - 2.5 <= -15.0f / 0.8f ||
		tacoma->coordenadas.z + 2.5 >= 10.0f / 0.8f ||
		tacoma->coordenadas.z - 2.5 <= -10.0 / 0.8f)
	{
		exit(0);
	}
}

void checarFrutitas() {

	if (tacoma->coordenadas.x <= 1.0f / 0.8f && tacoma->coordenadas.z <= 1.0f / 0.8f)
	{
		if (tacoma->coordenadas.x >= -1.0f / 0.8f && tacoma->coordenadas.z  <= -1.0f / 0.8f)
		{
			exit(0);
		}
	}


}
void actualizar() { 
	double tiempoActual = glfwGetTime();
	double tiempoDelta = tiempoActual - tiempoAnterior;

	

	/*int estadoDerecha = glfwGetKey(window,GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		posicionCamara.x += 0.01;
	}

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		posicionCamara.x -= 0.01;
	}*/
	
	//Movimiento tacoma
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		tacoma->direccion = 0;
	}
	
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		tacoma->direccion = 1;
	}

	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		tacoma->direccion = 2;
	}

	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		tacoma->direccion = 3;
	}

	checarColisiones();
	checarFrutitas();
	tacoma->mover(tiempoDelta);

	actualizarVista();
	cuadrado->vista = vista;
	tacoma->vista = vista;

	tiempoAnterior = tiempoActual;
}

void dibujar() {
	
	cuadrado->dibujar(GL_TRIANGLES);
	tacoma->dibujar(GL_TRIANGLES);
	fruta->dibujar(GL_TRIANGLES);
	hoja->dibujar(GL_TRIANGLES);
}

void inicializarFigura() {
	
}
void inicializarHoja() {
	hoja = new Modelo();
	srand(time(NULL));

	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-1.0f, 3.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-0.0f, 2.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-0.0f, 2.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	hoja->vertices.push_back({ vec4(-1.0f, 3.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-0.0f, 2.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-1.0f, 2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	hoja->vertices.push_back({ vec4(-1.0f, 3.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	hoja->vista = vista;
	hoja->proyeccion = proyeccion;


	hoja->mapaUV.push_back(vec2(0.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(1.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(0.0f, 1.0f));

	hoja->mapaUV.push_back(vec2(0.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(1.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(0.0f, 1.0f));

	hoja->mapaUV.push_back(vec2(0.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(1.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(0.0f, 1.0f));

	hoja->mapaUV.push_back(vec2(0.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(1.0f, 0.0f));
	hoja->mapaUV.push_back(vec2(0.0f, 1.0f));

}
void inicializarFruta() {
	fruta = new Modelo();
	srand(time(NULL));

	/* Fruta */
	fruta->vertices.push_back({ vec4(0.0f, 2.0f, 0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(0.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(0.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	fruta->vertices.push_back({ vec4(-0.0f, 2.0f, -0.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	fruta->vista = vista;
	fruta->proyeccion = proyeccion;

	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));

	fruta->mapaUV.push_back(vec2(1.0f, 1.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));

	fruta->mapaUV.push_back(vec2(0.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));

	fruta->mapaUV.push_back(vec2(0.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));

	fruta->mapaUV.push_back(vec2(0.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));

	fruta->mapaUV.push_back(vec2(0.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(1.0f, 0.0f));
	fruta->mapaUV.push_back(vec2(0.0f, 1.0f));

}



void inicializarCuadrado() {
	cuadrado = new Modelo();
	srand(time(NULL));

	// Z Negativa = atrás
	// Z Positiva = adelante


	//Parte Enfrente -- Pared Abajo
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Atrás -- Pared Abajo
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 9.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, 9.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Arriba -- Pared Abajo

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Enfrente -- Pared Arriba
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Atrás -- Pared Arriba
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -9.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, -9.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Arriba -- Pared Arriba

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -9.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	//Parte Izquierda -- Pared Izquierda

	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Derecha -- Pared Izquierda

	cuadrado->vertices.push_back({ vec4(-14.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-14.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-14.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-14.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-14.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-14.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Izquierda -- Pared Derecha

	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(15.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Derecha -- Pared Derecha

	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(14.0f, -1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(14.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(14.0f, -1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Arriba -- Pared Derecha

	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(14.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, -10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(15.0f, 1.0f, 10.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Rectangulo -- Izq

	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, -1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	//Rectangulo -- Der

	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, -1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Rectangulo -- Arriba


	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	//Rectangulo -- Enfrente


	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-2.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-2.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-10.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado1 -- Izq

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado1 -- Izq

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado1 -- Arriba

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	
	//Cuadrado1 -- Enfrente

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado2 -- Izq

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado2 -- Arriba

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 2.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Cuadrado2 -- Enfrente

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(11.0f, 1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(11.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 6.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });














// CUADRADO
	
	/*Parte Derecha
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Arriba
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Izquierda 
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4(float(rand() % 101) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	//Parte Abajo
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	*/
	cuadrado->vista = vista;
	cuadrado->proyeccion = proyeccion;

	/*cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));

	cuadrado->mapaUV.push_back(vec2(1.0f, 1.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));

	cuadrado->mapaUV.push_back(vec2(0.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(1.0f, 0.0f));
	cuadrado->mapaUV.push_back(vec2(0.0f, 1.0f));*/
}



int main()
{
	
	

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;


	red = green = blue = 0.75f;

	posicionCamara = vec3(6.0f, 35.0f, 15.0f);

	actualizarVista();
	inicializarProyeccion();

	inicializarFigura();
	inicializarCuadrado();
	inicializarFruta();
	inicializarHoja();

	tacoma = new Tacoma();
	tacoma->vista = vista;
	tacoma->proyeccion = proyeccion;

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	modeloID =
		glGetUniformLocation(shader->getID(), "modelo");
	vistaID =
		glGetUniformLocation(shader->getID(), "vista");
	proyeccionID =
		glGetUniformLocation(shader->getID(), "proyeccion");

	samplerImagenID =
		glGetUniformLocation(shader->getID(), "samplerImagen");
	coordenadaUVID =
		glGetAttribLocation(shader->getID(), "coordenadaUV");

	texturaUnoID =
		Shader::cargarBMP("texturas\\pera.bmp");

	texturaDosID =
		Shader::cargarBMP("texturas\\hoja.bmp");
	texturaTacomaID =
		Shader::cargarBMP("texturas\\pac.bmp");
	texturaPacmanID =
		Shader::cargarBMP("texturas\\pac.bmp");
	//Desenlazar shader
	shader->desenlazarShader();

	
	cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID, 
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaUnoID);


	fruta->shader = shader;
	fruta->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaUnoID);
	hoja->shader = shader;
	hoja->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaDosID);

	tacoma->shader = shader;
	tacoma->inicializarVertexArray(posicionID, colorID,
		modeloID, vistaID, proyeccionID, coordenadaUVID,
		samplerImagenID, texturaTacomaID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

