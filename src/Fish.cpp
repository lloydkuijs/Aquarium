#include "Fish.h"
#include <random>
#include <math.h>
#include "Graphics.h"
#include "Game.h"

void Test(const poscol::Collider& col)
{

}
aquatic::Fish::Fish(float movementSpeed, Color color, const std::string& name, int width, int height)
{
    targetLocation = poscol::Vector2{ 0,0 };
    _movementSpeed = movementSpeed;
    collider = poscol::RectangleCollider();
    this->_size = Size{ width, height };
    _color = color;
    _name = name;

    collider.size = { (float)width, (float)height };

    //collider.OnCollision(this->OnCollision);
}

aquatic::Size aquatic::Fish::GetSize() const
{
    return _size;
}

aquatic::Color aquatic::Fish::GetColor() const
{
    return _color;
}

void aquatic::Fish::ChangeColor(Color color)
{
    _color = color;
}

std::string aquatic::Fish::GetName() const
{
    return _name;
}

bool aquatic::Fish::IsAtTarget()
{
    return collider.position == targetLocation;
}

void aquatic::Fish::OnCollision(const poscol::Collider& collider)
{
    poscol::Vector2 n_collision = (collider.position - this->collider.position).Normalize();

    n_collision = n_collision * -100;

    targetLocation = this->collider.position + n_collision;
}

void aquatic::Fish::PickRandomTarget()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> pick_x(0, Graphics::SCREEN_WIDTH);
    std::uniform_int_distribution<> pick_y(0, Graphics::SCREEN_HEIGHT);

    targetLocation.x = pick_x(gen);
    targetLocation.y = pick_y(gen);
}

void aquatic::Fish::Update()
{
    if (!IsAtTarget())
    {
        poscol::Vector2 difference = targetLocation - collider.position;
        poscol::Vector2 normalized = difference.Normalize();

        float stepsize = _movementSpeed * Game::deltaTime;

        if (difference.Magnitude() < stepsize)
        {
            collider.position = targetLocation;
        }
        else
        {
            collider.velocity = (normalized * _movementSpeed);

            collider.position = collider.position + collider.velocity * Game::deltaTime;
        }
    }
    else
    {
        PickRandomTarget();
    }
}
