#include "Fish.h"

Fish::Fish(const Vector2& spawnLocation, float movementSpeed, Color color, const std::string& name, const Vector2& size)
{
    _spawnLocation = spawnLocation;
    _movementSpeed = movementSpeed;
    _currentLocation = spawnLocation;
    _targetLocation = _currentLocation;
    _size = size;
    _color = color;
    _name = name;
}

Vector2 Fish::GetLocation() const
{
    return _currentLocation;
}

Vector2 Fish::GetSpawnLocation() const
{
    return _spawnLocation;
}

Vector2 Fish::GetTargetLocation() const
{
    return _targetLocation;
}

Color Fish::GetColor() const
{
    return _color;
}

std::string Fish::GetName() const
{
    return _name;
}

Vector2 Fish::GetSize() const
{
    return _size;
}

bool Fish::IsAtTarget()
{
    return _currentLocation == _targetLocation;
}

void Fish::PickRandomTarget(int x_constraint, int y_constraint)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> pick_x(0, x_constraint - _size.x);
    std::uniform_int_distribution<> pick_y(0, y_constraint - _size.y);

    _targetLocation.x = pick_x(gen);
    _targetLocation.y = pick_y(gen);
}

void Fish::Update(float delta_time)
{
    if (!IsAtTarget())
    {
        Vector2 difference = _targetLocation - _currentLocation;
        Vector2 normalized = difference.Normalize();

        float step_size = _movementSpeed * delta_time;

        if (difference.Magnitude() < step_size)
        {
            _currentLocation = _targetLocation;
        }
        else
        {
            _currentLocation = _currentLocation + (normalized * _movementSpeed * delta_time);
        }
    }
    else
    {
        std::cout << "At location!!" << std::endl;
    }
}

Vector2 Vector2::Normalize()
{
    Vector2 vector{ x, y };

    float magnitude = sqrt(x * x + y * y);

    return vector / magnitude;
}

float Vector2::Magnitude()
{
    return sqrt(x * x + y * y);
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
