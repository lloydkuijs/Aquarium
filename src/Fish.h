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

	public:
		poscol::RectangleCollider collider;
		poscol::Vector2 targetLocation;

		Fish(float movementSpeed, Color color, const std::string& name, int width, int height, poscol::Vector2 start_position);

		Size GetSize() const;
		Color GetColor() const;
		void ChangeColor(Color color);
		std::string GetName() const;
		bool IsAtTarget();
		void PickRandomTarget();

		void Update();

		// Overload from function in base class
		void OnCollision(const aquatic::Fish& collider);

	};
}



