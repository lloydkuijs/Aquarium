#include "Fish.h"
#include <random>
#include <math.h>
#include "Graphics.h"

Fish::Fish(float movementSpeed, Color color, const std::string& name, const Size& size)
{
    _movementSpeed = movementSpeed;
    location = Vector2{ 0,0 };
    targetLocation = Vector2{ 0,0 };
    spawnLocation = Vector2{ 0,0 };
    _color = color;
    _name = name;
    this->size = size;
}

Fish::Fish(float movementSpeed, Color color, const std::string& name, const Size& size, const Vector2& spawnLocation)
{
    _movementSpeed = movementSpeed;
    location = spawnLocation;
    targetLocation = spawnLocation;
    this->spawnLocation = spawnLocation;
    _color = color;
    _name = name;

    this->size = size;
}

bool Fish::IsColliding(const Fish& fishA, const Fish& fishB)
{
    Vector2 location_a = fishA.location;
    Vector2 location_b = fishB.location;

    float a_left = location_a.x;
    float a_right = location_a.x + fishA.GetHeight();
    float a_top = location_a.y;
    float a_bottom = location_a.y + fishA.GetWidth();

    float b_left = location_b.x;
    float b_right = location_b.x + fishB.GetHeight();
    float b_top = location_b.y;
    float b_bottom = location_b.y + fishB.GetWidth();

    // If BOTH the x and y overlap
    if (b_left <= a_right && a_left <= b_right && b_top <= a_bottom && a_top < b_bottom) 
    {
        return true;
    }

    return false;
}

void Fish::ResolveCollision(Fish& fishA, Fish& fishB)
{
    Vector2 collision_angle = (fishB.location - fishA.location).Abs();

    Vector2 location_a = fishA.location;
    Vector2 location_b = fishB.location;

    float a_left = location_a.x;
    float a_right = location_a.x + fishA.GetHeight();
    float a_top = location_a.y;
    float a_bottom = location_a.y + fishA.GetWidth();

    float b_left = location_b.x;
    float b_right = location_b.x + fishB.GetHeight();
    float b_top = location_b.y;
    float b_bottom = location_b.y + fishB.GetWidth();

    Vector2 collision = Vector2::Null();

    if (a_left < b_left)
    {
        collision.x = a_right - b_left;
    }
    else
    {
        collision.x = b_right - b_left;
    }

    if (a_bottom < b_top)
    {
        collision.y = a_bottom - b_top;
    }
    else
    {
        collision.y = b_bottom - a_top;
    }

    if (collision.x < collision.y)
    {
        // Move the X
        float stepX = collision.x / 2;

        if (a_left < b_left)
        {
            fishA.location.x -= stepX;
            //fishB.location.x += stepX;
        }
        else
        {
            fishA.location.x += stepX;
            //fishB.location.x -= stepX;
        }
    }
    else if (collision.x > collision.y)
    {
        float stepY = collision.y;

        if (a_left < b_left)
        {
            fishA.location.y -= stepY;
            //fishB.location.y += stepY;
        }
        else
        {
            fishA.location.y += stepY;
            //fishB.location.y -= stepY;
        }
    }
    else
    {
        // move the X and y
        float stepX = collision.x;

        if (a_left < b_left)
        {
            fishA.location.x -= stepX;
            //fishB.location.x += stepX;
        }
        else
        {
            fishA.location.x += stepX;
            //fishB.location.x -= stepX;
        }

        float stepY = collision.y / 2;

        if (a_left < b_left)
        {
            fishA.location.y -= stepY;
            //fishB.location.y += stepY;
        }
        else
        {
            fishA.location.y += stepY;
            //fishB.location.y -= stepY;
        }
    }
}

float Fish::GetHeight() const
{
    return size.height;
}

float Fish::GetWidth() const
{
    return size.width;
}

Color Fish::GetColor() const
{
    return _color;
}

void Fish::SetColor(Color color)
{
    _color = color;
}

std::string Fish::GetName() const
{
    return _name;
}

bool Fish::IsAtTarget()
{
    return location == targetLocation;
}

void Fish::OnCollision(const Fish& fish)
{
    Vector2 n_collision = (fish.location - location).Normalize();

    n_collision = n_collision * -100;

    targetLocation = location + n_collision;

    //PickRandomTarget(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
}

void Fish::PickRandomTarget(int x_constraint, int y_constraint)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> pick_x(0, x_constraint - size.width);
    std::uniform_int_distribution<> pick_y(0, y_constraint - size.height);

    targetLocation.x = pick_x(gen);
    targetLocation.y = pick_y(gen);
}

void Fish::Update(float delta_time)
{
    if (!IsAtTarget())
    {
        Vector2 difference = targetLocation - location;
        Vector2 normalized = difference.Normalize();

        float stepsize = _movementSpeed * delta_time;

        if (difference.Magnitude() < stepsize)
        {
            location = targetLocation;
        }
        else
        {
            velocity = (normalized * _movementSpeed);

            location = location + velocity * delta_time;
        }
    }
    else
    {
        PickRandomTarget(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
    }
}

Vector2 Vector2::Normalize() const
{
    Vector2 vector{ x, y };

    float magnitude = sqrt(x * x + y * y);

    return vector / magnitude;
}

float Vector2::Magnitude() const
{
    return sqrt(x * x + y * y);
}

Vector2 Vector2::Abs()
{
    return Vector2{ std::abs(x), std::abs(y) };
}

Vector2 Vector2::operator*(float multiplier) const
{
    return Vector2{ x * multiplier, y * multiplier };
}

Vector2 Vector2::operator/(float diviser) const
{
    return Vector2{ x / diviser, y / diviser };
}

Vector2 Vector2::operator+(const Vector2& vector) const
{
    return Vector2{ x + vector.x, y + vector.y };
}

Vector2 Vector2::operator-(const Vector2& vector) const
{
    return Vector2{ x - vector.x, y - vector.y };
}

bool Vector2::operator==(const Vector2& vector) const
{
    return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector) const
{
    return x != vector.x || y != vector.y;
}
