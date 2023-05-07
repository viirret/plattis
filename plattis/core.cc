#include "core.hh"
#include "rectangle.hh"
#include "util.hh"

namespace plattis
{

Core::Core(const std::string& title)
    :   m_window(title), 
        m_renderer(m_window.getWindow()), 
        m_world(new b2World(b2Vec2(0.0f, 9.8f))),
        m_camera(m_window.getSizeX(), m_window.getSizeY()),

        m_player(m_renderer.getRenderer(), m_world, &m_camera),
        m_map(m_window.getSizeX(), m_window.getSizeY(), &m_player),
        m_windowSize({0, 0, m_window.getSizeX(), m_window.getSizeY()}), m_running(true),
        m_spawnEnemiesThread([this]() 
        {
            while (m_running)
            {
                // Sleep for 5 seconds.
                std::this_thread::sleep_for(std::chrono::seconds(5));

                // Add a new enemy.
                {
                    std::lock_guard<std::mutex> lock(m_enemiesMutex);
                    m_enemies.emplace_back(m_renderer.getRenderer(), m_world, &m_camera, (static_cast<float>(m_window.getSizeX()) / 10 * 
                                static_cast<float>(randomValue(0, 9))), m_player.getY() - 500.0f);
                }

                // Remove the oldest enemy.
                if (m_enemies.size() > 6)
                {
                    std::lock_guard<std::mutex> lock(m_enemiesMutex);
                    m_enemies.pop_front();
                }
            }
        })
{
}

Core::~Core()
{
    m_running = false;
    m_spawnEnemiesThread.join();
}

void Core::start()
{
    while (m_running)
    {
        updatePlattis();
    }
}

void Core::updatePlattis()
{
    // Set up timer for fixed time step.
    const float timeStep = 1.0f / 60.0f; // 60 frames per second
    Uint32 currentTime = SDL_GetTicks();
    float accumulator = 0;

    while (m_running)
    {
        Uint32 newTime = SDL_GetTicks();
        float deltaTime = static_cast<float>(newTime - currentTime);
        currentTime = newTime;
        accumulator += deltaTime;

        // Process events.
        trackEvents();

        // Update game state at a fixed rate.
        while (accumulator >= timeStep * 1000)
        {
            update(timeStep);
            accumulator -= timeStep * 1000;
        }

        // Update map.
        m_map.update(m_world);

        // Render the game state.
        render();
    }
}

void Core::update(float deltaTime)
{
    // Update Box2D physics.
    const int velocityIterations = 6;
    const int positionIterations = 2;
    m_world->Step(deltaTime, velocityIterations, positionIterations);

    // update enemies
    for(auto& enemy : m_enemies)
    {
        enemy.update();
    }

    // Update player
    m_player.update(deltaTime);
}

void Core::render()
{
    m_renderer.clear();

    // Update background color.
    m_renderer.fillRect(m_windowSize, m_backgroundColor);

    m_map.render(m_renderer, &m_camera);

    // Render the game state
    m_player.draw(m_renderer.getRenderer());

    for(auto& enemy : m_enemies)
    {
        enemy.draw(m_renderer.getRenderer());
    }

    m_renderer.render();
}


void Core::setBackgroundColor(const Color& color) { m_backgroundColor = color; }

void Core::trackEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                m_running = false;
                break;
            }

            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        m_running = false;
                        break;
                    }

                    case SDLK_LEFT:
                    {
                        m_player.moveLeft();
                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        m_player.moveRight();
                        break;
                    }

                    case SDLK_SPACE:
                    {
                        m_player.jump();
                        break;
                    }
                }
                break;
            }

            case SDL_KEYUP:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                    {
                        m_player.stopMovingLeft();
                        break;
                    }

                    case SDLK_RIGHT:
                    {
                        m_player.stopMovingRight();
                        break;
                    }
                }
                break;
            }
        }
    }
}

}
