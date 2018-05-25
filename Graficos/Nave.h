#pragma once
#include "Modelo.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"


class Nave : public Modelo {
public:
	Nave();
	float angulo;
	vec3 coordenadas;
	float velocidadAngular = 0.003f;
	float velocidad = 0.0005f;
	void rotarNave(int direccion);
	void moverNave();
};