#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include <iostream>



class Transform : public Component { // Contiene los parametros "basicos" de las entidades y funciones para consultarlos y cambiarlos
private:
	Vector2D position;
	Vector2D velocity;
	Vector2D direction;
	float width;
	float height;
	float rotation;

	void setDir();

public:
	Transform();
	Transform(Vector2D Position, Vector2D Velocity, float Width, float Heigth, float Rotation = 0);
	virtual ~Transform() {}

	void update();

	float getW();
	float getH();
	float getR();
	inline Vector2D getDir() { return direction; }
	inline Vector2D getPos() { return position; }
	inline Vector2D getVel() { return velocity; }


	void setR(float valRot);
	void setH(float valHei);
	void setW(float valWid);
	void setPos(Vector2D Velocity);
	void setPosX(float X);
	void setPosY(float Y);
	void setVel(Vector2D Velocity);
};