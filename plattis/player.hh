#ifndef PLATTIS_PLAYER_HH
#define PLATTIS_PLAYER_HH

#include "image.hh"
#include "camera.hh"

#include <box2d/box2d.h>

namespace plattis
{

class Player : public Image
{
public:
    /// Constructor.
    Player(SDL_Renderer* renderer, b2World* world, Camera* camera);

    /// Update the player.
    /// \param deltaTime
    void update(float deltaTime);

    void moveLeft();
    void moveRight();

    void jump();

    void stopMovingLeft();
    void stopMovingRight();

    float getX() override { return m_body->GetPosition().x; }
    float getY() override { return m_body->GetPosition().y; }

private:

    void applyHorizontalForce(float force);

private:
    b2World* m_world;
    b2Body* m_body;
    Camera* m_camera;
    b2Fixture* m_fixture;

private:

    float m_maxSpeed = 100;
    float m_jumpImpulse = -1000000.0f;

private:

    bool m_moveLeft = false;
    bool m_moveRight = false;
};

}

#endif
