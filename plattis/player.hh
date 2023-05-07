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

    /// Move the player to the left.
    void moveLeft();

    /// Move the player to the right.
    void moveRight();

    /// Jump the player.
    void jump();

    /// Stop the movement to the left.
    void stopMovingLeft();

    /// Stop the movement to the right.
    void stopMovingRight();

    /// Get the x position of the player.
    /// \return float The x position.
    float getX() override { return m_body->GetPosition().x; }

    /// Get the y position of the player.
    /// \return float The y position.
    float getY() override { return m_body->GetPosition().y; }

    /// Get players position compared to screen.
    /// \return b2Vec2 Position compared to screen.
    b2Vec2 worldPos()
    {
        return m_camera->ConvertWorldToScreen(m_body->GetPosition());
    }

private:

    /// Apply force to m_body.
    /// \param float The force.
    void applyHorizontalForce(float force);

private:

    b2World* m_world;
    b2Body* m_body;
    Camera* m_camera;
    b2Fixture* m_fixture;

private:

    float m_maxSpeed = 2000;
    float m_jumpImpulse = -40000000.0f;

private:

    bool m_moveLeft = false;
    bool m_moveRight = false;
};

}

#endif
