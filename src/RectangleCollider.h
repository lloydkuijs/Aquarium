#pragma once

#include "Collider.h"
#include "GameObject.h"


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
        RectangleCollider();

        // overload base functions
        void Collide(RectangleCollider& collider) override;
        bool IsColliding(RectangleCollider& collider) override;

        float GetHeight() const;
        float GetWidth() const;

        float GetTop() const;
        float GetLeft() const;
        float GetRight() const;
        float GetBottom() const;

    };
};

