#ifndef PLATTIS_RENDERER_HH
#define PLATTIS_RENDERER_HH

#include "color.hh"

#include <SDL2/SDL.h>

namespace plattis
{

class Renderer
{
public:
    /// Constructor.
    Renderer(SDL_Window* window);

    /// Destructor.
    ~Renderer();
    
    /// Clear SDL rendering.
    void clear();

    /// Do main SDL rendering.
    void render();

    /// Draw outlines of SDL rectangle.
    void drawRect(SDL_Rect rect, const Color& color);
    
    /// Fill the rendering area with color.
    void fillRect(SDL_Rect rect, const Color& color);

    /// Set SDL drawing color.
    void setDrawColor(const Color& color);

    /// Get's the SDL renderer.
    /// \return SDL_Renderer*
    SDL_Renderer* getRenderer() { return m_renderer; }

private:
    SDL_Renderer* m_renderer;
};

}

#endif
