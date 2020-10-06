#pragma once

#include <iostream>

struct Vector2
{
	float x, y;

	Vector2 Normalize() const;
	float Magnitude() const;
	Vector2 Abs();

	Vector2 operator*(float multiplier) const;
	Vector2 operator/(float diviser) const;
	Vector2 operator+(const Vector2& vector) const;
	Vector2 operator-(const Vector2& vector) const;
	bool operator==(const Vector2& vector) const;
	bool operator!=(const Vector2& vector) const;

	inline static Vector2 Null() { return Vector2{ 0,0 }; };

	inline void Print()
	{
		std::cout << "X: " << x << " y: " << y << "\n";
	}
};

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
	Vector2 location;
	Vector2 targetLocation;
	Vector2 spawnLocation;
	Vector2 velocity;
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


