#pragma once

#include "Collider.h"

namespace poscol
{
    struct Size
    {
        float width, height;
    };

    class RectangleCollider : public Collider
    {
    public:
        Size size;

        // Inherited via Collider
        virtual void Update() override;
        void Collide(RectangleCollider& collider);
    };
};

