#ifndef PLATTIS_ENEMY_HH
#define PLATTIS_ENEMY_HH

#include "image.hh"
#include "camera.hh"

#include <box2d/b2_world.h>

namespace plattis
{

/// This class creates Enemy object that is derived from Image

class Enemy : public Image
{
public:
    /// Constructor
    /// \param renderer SDL renderer.
    /// \param world b2World.
    /// \param camera Our camera object.
    /// \param x The enemy x position.
    /// \param y The enemy y position.
    Enemy(SDL_Renderer* renderer, b2World* world, Camera* camera, float x, float y);

    /// Move constructor.
    /// \param other Other enemy.
    Enemy(Enemy&& other);

    Enemy(const Enemy& other) = delete;

    /// Update enemy.
    void update();

    /// Get the x position of the enemy.
    /// \return float The x position.
    float getX() override { return m_body->GetPosition().x; }

    /// Get the y position of the enemy.
    /// \return float The y position.
    float getY() override { return m_body->GetPosition().y; }

protected:

    /// Initialize all Box2D variables.
    void createB2Object();

protected:

    SDL_Renderer* m_renderer;
    b2World* m_world;
    b2Body* m_body;
    Camera* m_camera;
    b2Fixture* m_fixture;

protected:
    float m_maxSpeed = 1000; 

};

}

#endif
