#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Tacoma : public Modelo {
public:
	vec3 coordenadas;
	float angulo;
	int direccion = 0;
	float velocidad = 8.0f;
	Tacoma();
	void mover(double tiempoDelta);
};

