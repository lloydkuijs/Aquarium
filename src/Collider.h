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

class Collider
{
public:
    Vector2 position;
	Vector2 velocity;
	bool colliding;

    virtual void Update() = 0;
	virtual void Collide(Collider& collider2) = 0;

};

