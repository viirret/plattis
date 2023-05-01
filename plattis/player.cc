#include "player.hh"
#include "util.hh"

namespace plattis
{

Player::Player(SDL_Renderer* renderer, b2World* world, Camera* camera)
    :   Image(renderer, "../assets/doodle.png", 200, 200), 
        m_world(world),
        m_camera(camera)
{
    // Scale image to correct size.
    setScale(0.1f);

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
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.0f;
    m_fixture = m_body->CreateFixture(&fixtureDef);
}

void Player::applyHorizontalForce(float force)
{
    // Apply the force to the player's Box2D body.
    b2Vec2 impulse(force, 0.0f);
    m_body->ApplyLinearImpulseToCenter(impulse, true);
}

void Player::moveLeft()
{
    m_moveLeft = true;
}

void Player::moveRight()
{
    m_moveRight = true;
}

void Player::stopMovingLeft()
{
    m_moveLeft = false;
}

void Player::stopMovingRight()
{
    m_moveRight = false;
}

void Player::jump()
{
    b2Vec2 impulse(0.0f, m_jumpImpulse);

    // Check if the player is already jumping and has not reached the maximum velocity
    if (m_body->GetLinearVelocity().y > -10.0f) 
    {
        m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
    }
}

void Player::update(float deltaTime)
{
    // Apply forces based on movement flags.
    if (m_moveLeft)
    {
        applyHorizontalForce(-100000.0f);
    }

    if (m_moveRight)
    {
        applyHorizontalForce(100000.0f);
    }

    // Limit horizontal velocity.
    b2Vec2 vel = m_body->GetLinearVelocity();
    
    vel.x = clamp(vel.x, -m_maxSpeed, m_maxSpeed);

    m_body->SetLinearVelocity(vel);

    // Update position based on Box2D physics.
    //m_x = getX();
    //m_y = getY();

    // Set the camera position to be centered on the player.
    m_camera->setX(getX() - m_camera->getWidth() / 2);
    m_camera->setY(getY() - m_camera->getHeight() / 2);

    // Update position of the player image based on the camera.
    m_x = getX() - m_camera->getX();
    m_y = getY() - m_camera->getY();


}

}
