#include "Collider.h"
#include <stdexcept>

poscol::Vector2 poscol::Vector2::Normalize() const
{
    Vector2 vector{ x, y };

    float magnitude = sqrt(x * x + y * y);

    return vector / magnitude;
}

float poscol::Vector2::Magnitude() const
{
    return sqrt(x * x + y * y);
}

poscol::Vector2 poscol::Vector2::Abs()
{
    return Vector2{ std::abs(x), std::abs(y) };
}

poscol::Vector2 poscol::Vector2::operator*(float multiplier) const
{
    return Vector2{ x * multiplier, y * multiplier };
}

poscol::Vector2 poscol::Vector2::operator/(float diviser) const
{
    return Vector2{ x / diviser, y / diviser };
}

poscol::Vector2 poscol::Vector2::operator+(const Vector2& vector) const
{
    return Vector2{ x + vector.x, y + vector.y };
}

poscol::Vector2 poscol::Vector2::operator-(const Vector2& vector) const
{
    return Vector2{ x - vector.x, y - vector.y };
}

void poscol::Vector2::operator+=(const Vector2& vector)
{
    this->x += vector.x;
    this->y += vector.y;
}

bool poscol::Vector2::operator==(const Vector2& vector) const
{
    return x == vector.x && y == vector.y;
}

bool poscol::Vector2::operator!=(const poscol::Vector2& vector) const
{
    return x != vector.x || y != vector.y;
}

poscol::Collider::Collider()
{
    position = { 0,0 };
    velocity = { 0,0 };
    col_callback = nullptr;
}

void poscol::Collider::Collide(Collider& collider2)
{
    // Not supported
    std::cout << "Unimplemented collision!! Overload the function." << std::endl;
}

void poscol::Collider::Translate(Vector2 vector)
{
    this->position += vector;
}

void poscol::Collider::OnCollision(void(*onCollision)(const Collider&))
{
    this->col_callback = onCollision;
}
