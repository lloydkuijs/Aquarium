#pragma once

#include <iostream>
#include <random>
#include <math.h>

struct Vector2
{
	float x, y;

	Vector2 Normalize();
	float Magnitude();

	Vector2 operator*(float multiplier) const;
	Vector2 operator/(float diviser) const;
	Vector2 operator+(const Vector2& vector) const;
	Vector2 operator-(const Vector2& vector) const;
	bool operator==(const Vector2& vector) const;
	bool operator!=(const Vector2& vector) const;

};

enum class Color {
	red,
	green,
	blue,
};

class Fish
{

private:
	Vector2 _currentLocation;
	Vector2 _targetLocation;
	Vector2 _spawnLocation;
	float _movementSpeed;
	Color _color;
	std::string _name;
	Vector2 _size;

public:
	Fish(const Vector2& spawnLocation, float movementSpeed, Color color, const std::string& name, const Vector2& size);


	static bool IsColliding(const Fish& fishA, const Fish& fishB);

	Vector2 GetLocation() const;
	Vector2 GetSpawnLocation() const;
	Vector2 GetTargetLocation() const;
	Color GetColor() const;
	void SetColor(Color color);
	std::string GetName() const;
	Vector2 GetSize() const;

	bool IsAtTarget();
	void PickRandomTarget(int x_constraint, int y_constraint);
	void Update(float delta_time);
};


