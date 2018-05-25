#include "stdafx.h"
#include "Tacoma.h"

Tacoma::Tacoma() {
	//Inicializar transformaciones
	angulo = 90.0f;
	coordenadas = vec3(12.0f, 0.0f, 0.0f);
	direccion = 1;

	//Parte central del carro





	vertices.push_back({ vec4(0.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, 0.5f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(0.0f, -2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(0.0f, -2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	// Boca //
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.0f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//Boca 2 
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	// Atras
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -0.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	// Meow

	vertices.push_back({ vec4(-2.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.0f, -2.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.0f, -2.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.0f, -2.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(0.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//adsadas
	vertices.push_back({ vec4(-1.0f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	//medio	
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, 0.0f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.5f, 0.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, 0.0f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-1.5f, 0.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-0.5f, 1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, 0.0f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, 0.0f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, 0.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -1.5f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(0.0f, -2.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(0.0f, -2.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-1.5f, -2.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-0.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	vertices.push_back({ vec4(-0.5f, -1.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(1.0f, -1.5f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	vertices.push_back({ vec4(-2.0f, -2.5f, -3.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });


	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));
	mapaUV.push_back(vec2(0.0f, 0.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));


	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));

	mapaUV.push_back(vec2(1.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
	mapaUV.push_back(vec2(2.0f, 1.0f));
}

void Tacoma::mover(double tiempoDelta) {
	switch (direccion) {
	case 0: //derecha
		coordenadas.x += velocidad * tiempoDelta;
		angulo = 0.0f * 3.14159f / 180.0f;
		break;
	case 1: //izquierda
		coordenadas.x -= velocidad * tiempoDelta;
		angulo = 180.0f * 3.14159f / 180.0f;
		break;
	case 2: //arriba
		coordenadas.z -= velocidad * tiempoDelta;
		angulo = 90.0f * 3.14159f / 180.0f;
		break;
	case 3: //abajo
		coordenadas.z += velocidad * tiempoDelta;
		angulo = 270.0f * 3.14159f / 180.0f;
		break;
	default:
		break;
	}


	modelo = mat4(1.0f); //Matriz identidad
	modelo = scale(vec3(0.8f, 0.8f, 0.8f));
	modelo = translate(modelo, coordenadas);
	modelo = rotate(modelo, angulo, vec3(0.0f, 1.0f, 0.0f));
	
}