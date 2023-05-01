#ifndef PLATTIS_PLATFORM_HH
#define PLATTIS_PLATFORM_HH

#include "rectangle.hh"

#include <box2d/box2d.h>

namespace plattis
{

/// This class creates Rectangle that has Box2D body

class Platform : public Rectangle
{
public:
    Platform(int x, int y, int w, int h, b2World* world)
        : Rectangle(x, y, w, h)
    {
        // Create Box2D body.
        b2BodyDef bodyDef; 
        bodyDef.type = b2_staticBody;
        bodyDef.position.Set(static_cast<float>(x), static_cast<float>(y));
        m_body = world->CreateBody(&bodyDef);

        // Create Box2D shape and fixture.
        b2PolygonShape shape;
        shape.SetAsBox(static_cast<float>(w) / 2.0f, static_cast<float>(h) / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution = 0.0f;
        m_fixture = m_body->CreateFixture(&fixtureDef);
    }

private:
    b2Body* m_body;
    b2Fixture* m_fixture;
};

}

#endif
