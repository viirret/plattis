#ifndef PLATTIS_CORE_HH
#define PLATTIS_CORE_HH

#include "player.hh"
#include "rectangle.hh"
#include "platform.hh"
#include "renderer.hh"
#include "window.hh"
#include "camera.hh"
#include "enemy.hh"
#include "map.hh"

#include <deque>
#include <thread>
#include <mutex>

namespace plattis
{

/// This class creates core for the plattis game.

class Core
{
public:
    /// Constructor.
    Core(const std::string& title);

    ~Core();

    /// Start plattis.
    void start();

protected:
    /// Set the background color
    void setBackgroundColor(const Color& color);

protected:
    Window m_window;
    Renderer m_renderer;

    b2World* m_world;

    Camera m_camera;

    Player m_player;
    Map m_map;

    SDL_Rect m_windowSize;

    std::mutex m_enemiesMutex;

private:
    /// Update core.
    void updatePlattis();

    /// Update logic.
    void update(float deltaTime);

    /// Update rendering.
    void render();

    /// Update events.
    void trackEvents();

private:

    std::thread m_spawnEnemiesThread;

    Color m_backgroundColor;

    bool m_running;

private:

    std::deque<Enemy> m_enemies;
};

}

#endif
