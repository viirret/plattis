#ifndef PLATTIS_CORE_HH
#define PLATTIS_CORE_HH

#include "player.hh"
#include "rectangle.hh"
#include "renderer.hh"
#include "window.hh"

namespace plattis
{

class Core
{
public:
    /// Constructor.
    Core(const std::string& title);

    /// Start plattis.
    void start();

protected:
    /// Set the background color
    void setBackgroundColor(const Color& color);

protected:
    Window m_window;
    Renderer m_renderer;

    b2World* m_world;
    Rectangle rectangle;
    Player m_player;

    SDL_Rect m_windowSize;

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
    Color m_backgroundColor;

    bool m_running;

    // Variables for updating time.
    const int m_fps = 1000 / 60;
    int m_lastTime = SDL_GetTicks();
    int m_currentTime;
    int m_elapsedTime;
};

}

#endif
