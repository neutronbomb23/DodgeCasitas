#include "Transform.h"


Transform::Transform() : Component() {
	position = Vector2D(0, 0);
	velocity = Vector2D(0, 0);
	width = 0;
	height = 0;
	direction = Vector2D(0, -1);
	rotation = 0;
}

Transform::Transform(Vector2D Position, Vector2D Velocity, float Width, float Heigth, float Rotation) : Component() {
	position = Position;
	velocity = Velocity;
	width = Width;
	height = Heigth;
	setR(Rotation);
}

void Transform::update() {
	position = position + velocity;
	cout << position.getX() << " " << position.getY() << endl;
}

float Transform::getW() {
	return width;
}

float Transform::getH() {
	return height;
}

float Transform::getR() {
	return rotation;
}

void Transform::setR(float Rotation) {
	rotation = Rotation; 
	setDir();
}

void Transform::setH(float Height) {
	height = Height;
}

void Transform::setW(float Width) {
	width = Width;
}

void Transform::setPos(Vector2D Position) {
	position = Position;
}

void Transform::setPosX(float X) {
	position.setX(X);
}

void Transform::setDir() {
	float angle = (rotation * 3,1416) / 180.0f;
	direction = Vector2D(sin(angle), -cos(angle));
}

void Transform::setPosY(float Y) {
	position.setY(Y);
}

void Transform::setVel(Vector2D Velocity) {
	velocity = Velocity;
}
