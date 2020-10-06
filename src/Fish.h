#pragma once

#include <iostream>
#include "Collider.h"

struct Size
{
	float width, height;
};

enum class Color {
	red,
	green,
	blue,
};

class Fish
{

private:
	bool _colliding;
	float _movementSpeed;
	Color _color;
	std::string _name;

// These vectors are public to not have to write an external interface for this class to make positional calculations, 
// I would consider this a problem in a larger sized application.
public:
	Vector2 targetLocation;
	Vector2 spawnLocation;
	
	Size size;

	Fish(float movementSpeed, Color color, const std::string& name, const Size& size);
	Fish(float movementSpeed, Color color, const std::string& name, const Size& size, const Vector2& spawnLocation);

	static bool IsColliding(const Fish& fishA, const Fish& fishB);
	static void ResolveCollision(Fish& fishA, Fish& fishB);

	float GetHeight() const;
	float GetWidth() const;
	Color GetColor() const;
	void SetColor(Color color);
	std::string GetName() const;
	bool IsAtTarget();
	void OnCollision(const Fish& fish);
	void PickRandomTarget();
	void Update();
};


