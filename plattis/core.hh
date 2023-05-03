#ifndef PLATTIS_CORE_HH
#define PLATTIS_CORE_HH

#include "player.hh"
#include "rectangle.hh"
#include "platform.hh"
#include "renderer.hh"
#include "window.hh"
#include "camera.hh"
#include "map.hh"

namespace plattis
{

/// This class creates core for the plattis game.

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

    Camera m_camera;

    /*
    Platform platform;

    Rectangle rectangle;
    Rectangle rectangle2;
    Rectangle rectangle3;
    Rectangle rectangle4;
    */

    Player m_player;
    Map m_map;

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
};

}

#endif
