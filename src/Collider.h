#pragma once

#include <iostream>


/// <summary>
/// Position and collision
/// </summary>
namespace poscol
{
	// Forward declaration
	class RectangleCollider;

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
		void operator+=(const Vector2& vector);
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

		Collider();

		virtual bool IsColliding(RectangleCollider& collider) = 0;
		virtual void Collide(RectangleCollider& collider) = 0;
		virtual void Translate(Vector2 vector);
	};

};

