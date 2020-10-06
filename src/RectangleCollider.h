#pragma once

#include "Collider.h"

class RectangleCollider : public Collider
{
public:
    // Inherited via Collider
    virtual void Update() override;
    virtual void Collide(Collider& collider) override;
    void Collide(RectangleCollider& collider);
};

