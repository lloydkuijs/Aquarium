#pragma once

#include <iostream>
#include <random>
#include <math.h>

struct Vector2
{
public:
	float x, y;

	bool Equal(const Vector2& vector) 
	{
		if (x == vector.x && y == vector.y) 
		{
			return true;
		}

		return false;
	}

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

public:
	Fish(const Vector2& spawnLocation, float movementSpeed, Color color, std::string& name, const Vector2& size);

	Vector2 GetLocation() const;
	Vector2 GetSpawnLocation() const;
	Vector2 GetTargetLocation() const;
	Color GetColor() const;
	std::string GetName() const;

	bool IsAtTarget();
	void PickRandomTarget(int x_constraint, int y_constraint);
	void Update(float delta_time);
};


