#include "RectangleCollider.h"
#include <iostream>

using namespace poscol;

void RectangleCollider::Update()
{
}

bool Colliding(RectangleCollider collider1, RectangleCollider collider2)
{

    Vector2 location_a = collider1.position;
    Vector2 location_b = collider2.position;

    float a_left = location_a.x;
    float a_right = location_a.x + collider1.size.width;
    float a_top = location_a.y;
    float a_bottom = location_a.y + collider1.size.height;

    float b_left = location_b.x;
    float b_right = location_b.x + collider2.size.width;
    float b_top = location_b.y;
    float b_bottom = location_b.y + collider2.size.height;

    // If BOTH the x and y overlap
    if (b_left <= a_right && a_left <= b_right && b_top <= a_bottom && a_top < b_bottom)
    {
        return true;
    }

    return false;
}

void ResolveCollision(RectangleCollider collider1, RectangleCollider collider2)
{
    Vector2 collision_angle = (collider2.position - collider1.position).Abs();

    Vector2 location_a = collider1.position;
    Vector2 location_b = collider2.position;

    float a_left = location_a.x;
    float a_right = location_a.x + collider1.size.width;
    float a_top = location_a.y;
    float a_bottom = location_a.y + collider1.size.height;

    float b_left = location_b.x;
    float b_right = location_b.x + collider2.size.width;
    float b_top = location_b.y;
    float b_bottom = location_b.y + collider2.size.height;

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
            collider1.position.y -= stepY;
            collider2.position.y += stepY;
        }
        else
        {
            collider1.position.y += stepY;
            collider2.position.y -= stepY;
        }
    }
    else if (collision.x < collision.y)
    {
        // Move the X
        float stepX = collision.x / 2;

        if (a_left < b_left)
        {
            collider1.position.x -= stepX;
            collider2.position.x += stepX;
        }
        else
        {
            collider1.position.x += stepX;
            collider2.position.x -= stepX;
        }
    }
    else
    {
        // move the X and y
        float stepX = collision.x;

        if (a_left < b_left)
        {
            collider1.position.x -= stepX;
            collider2.position.x += stepX;
        }
        else
        {
            collider1.position.x += stepX;
            collider2.position.x -= stepX;
        }

        float stepY = collision.y / 2;

        if (a_top < b_top)
        {
            collider1.position.y -= stepY;
            collider2.position.y += stepY;
        }
        else
        {
            collider1.position.y += stepY;
            collider2.position.y -= stepY;
        }
    }
}

void RectangleCollider::Collide(RectangleCollider& collider)
{
    if (Colliding(*this, collider))
    {
        if (col_callback != nullptr)
        {
            col_callback(collider);
        }

        if (collider.col_callback != nullptr)
        {
            collider.col_callback(*this);
        }
    }
}
