#version 330 core
//La primera linea es la version

//Atributos de entrada
layout(location = 0) in vec4 posicion;
in vec4 color;
in vec2 coordenadaUV;

uniform mat4 modelo;
uniform mat4 vista;
uniform mat4 proyeccion;
uniform sampler2D samplerImagen;

//Atributos de salida
out vec4 fragmentColor;
out vec2 fragmentCoordenadaUV;


//Funcion main
void main() {
	//Crear la matriz MVP
	mat4 MVP = proyeccion * vista * modelo;

	//La posicion de salida del vertice
	//Se guarda en gl_Position (vec4)
	gl_Position = MVP * posicion;

	//Establecer valor de fragmentColor
	fragmentColor = color;

	//Establecer el valor de fragmentCoordenadaUV
	fragmentCoordenadaUV = coordenadaUV;
}

