#include "RectangleCollider.h"
#include <iostream>

void RectangleCollider::Update()
{
}

void RectangleCollider::Collide(Collider& collider)
{
    // Not supported
    std::cout << "Unimplemented collision! Overload the function." << std::endl;
}

void RectangleCollider::Collide(RectangleCollider& collider)
{
}


void RectangleCollider::Update()
{
}
