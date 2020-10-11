#pragma once

#include "Collider.h"

class GameObject
{
public:
    virtual void OnCollision(const GameObject& gameObject);
    virtual void Update() = 0;
};

