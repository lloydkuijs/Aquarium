#include "RectangleCollider.h"
#include <iostream>

using namespace poscol;

poscol::RectangleCollider::RectangleCollider()
{
    size = { 0,0 };
}


void poscol::RectangleCollider::Collide(RectangleCollider& collider)
{
    Vector2 collision_angle = (collider.position - position).Abs();

    float a_left = GetLeft();
    float a_right = GetRight();
    float a_top = GetTop();
    float a_bottom = GetBottom();

    float b_left = collider.GetLeft();
    float b_right = collider.GetRight();
    float b_top = collider.GetTop();
    float b_bottom = collider.GetBottom();

    Vector2 collision = Vector2::Null();

    if (a_left < b_left)
    {
        collision.x = a_right - b_left;
    }
    else
    {
        collision.x = b_right - a_left;
    }

    if (a_bottom < b_bottom)
    {
        collision.y = a_bottom - b_top;
    }
    else
    {
        collision.y = b_bottom - a_top;
    }

    if (collision.x > collision.y)
    {
        float stepY = collision.y / 2;

        if (a_top < b_top)
        {
            position.y -= stepY;
            collider.position.y += stepY;
        }
        else
        {
            position.y += stepY;
            collider.position.y -= stepY;
        }
    }
    else if (collision.x < collision.y)
    {
        // Move the X
        float stepX = collision.x / 2;

        if (a_left < b_left)
        {
            position.x -= stepX;
            collider.position.x += stepX;
        }
        else
        {
            position.x += stepX;
            collider.position.x -= stepX;
        }
    }
    else
    {
        // move the X and y
        float stepX = collision.x / 2;

        if (a_left < b_left)
        {
            position.x -= stepX;
            collider.position.x += stepX;
        }
        else
        {
            position.x += stepX;
            collider.position.x -= stepX;
        }

        float stepY = collision.y / 2;

        if (a_top < b_top)
        {
            position.y -= stepY;
            collider.position.y += stepY;
        }
        else
        {
            position.y += stepY;
            collider.position.y -= stepY;
        }
    }
}

bool poscol::RectangleCollider::IsColliding(RectangleCollider& collider)
{
    float a_left = position.x;
    float a_right = position.x + this->size.width;
    float a_top = position.y;
    float a_bottom = position.y + this->size.height;

    float b_left = collider.position.x;
    float b_right = collider.position.x + collider.size.width;
    float b_top = collider.position.y;
    float b_bottom = collider.position.y + collider.size.height;

    // If BOTH the x and y overlap
    if (b_left <= a_right && a_left <= b_right && b_top <= a_bottom && a_top < b_bottom)
    {
        return true;
    }
    
    return false;
}

float poscol::RectangleCollider::GetHeight() const
{
    return size.height;
}

float poscol::RectangleCollider::GetWidth() const
{
    return size.width;
}

float poscol::RectangleCollider::GetTop() const
{
    return position.y;
}

float poscol::RectangleCollider::GetLeft() const
{
    return position.x;
}

float poscol::RectangleCollider::GetRight() const
{
    return position.x + size.width;
}

float poscol::RectangleCollider::GetBottom() const
{
    return position.y + size.height;
}
