#pragma once

#include <iostream>
#include "Collider.h"
#include "RectangleCollider.h"

namespace aquatic
{
	struct Size
	{
		int width, height;
	};

	enum class Color
	{
		red,
		green,
		blue,
	};

	class Fish
	{
	private:
		float _movementSpeed;
		Color _color;
		std::string _name;
		Size _size;

		// These vectors are public to not have to write an external interface for this class to make positional calculations, 
		// I would consider this a problem in a larger sized application.
	public:
		poscol::RectangleCollider collider;
		poscol::Vector2 targetLocation;

		Fish(float movementSpeed, Color color, const std::string& name, int width, int height);

		Size GetSize() const;
		Color GetColor() const;
		void ChangeColor(Color color);
		std::string GetName() const;
		bool IsAtTarget();
		void OnCollision(const poscol::Collider& collider);
		void PickRandomTarget();
		void Update();
	};
}



