#version 330 core
//version

in vec4 fragmentColor;
in vec2 fragmentCoordenadaUV;

//atributos
out vec4 salidaColor;

uniform sampler2D samplerImagen;

//funcion main
void main() {
	//salidaColor = fragmentColor;
	salidaColor = texture(samplerImagen, fragmentCoordenadaUV).rgba;
}