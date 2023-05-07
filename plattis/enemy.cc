#include "enemy.hh"
#include "util.hh"

namespace plattis
{

Enemy::Enemy(SDL_Renderer* renderer, b2World* world, Camera* camera, float x, float y) :
    Image(renderer, "../assets/enemy.png", x, y),
    m_renderer(renderer),
    m_world(world),
    m_camera(camera)
{
    // Scale image to correct size.
    setScale(0.1f);
    createB2Object();
}

Enemy::Enemy(Enemy&& other) :
    Image(std::move(other)),
    m_renderer(other.m_renderer),
    m_world(other.m_world),
    m_camera(other.m_camera)
{
    setScale(0.1f);
    createB2Object();
}

void Enemy::createB2Object()
{
    // Create Box2D body.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(m_x, m_y);
    m_body = m_world->CreateBody(&bodyDef);

    // Create the Box2D fixture for the player.
    b2PolygonShape shape;
    shape.SetAsBox(static_cast<float>(m_width) * m_scale / 2,
                   static_cast<float>(m_height) * m_scale / 2);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 10.0f;
    fixtureDef.friction = 0.9f;
    fixtureDef.restitution = 0.0f;
    m_fixture = m_body->CreateFixture(&fixtureDef);
}

void Enemy::update()
{
    // Update position of the enemy relative to the camera.
    m_x = getX() - m_camera->getX();
    m_y = getY() - m_camera->getY();
}

}
