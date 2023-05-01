#ifndef PLATTIS_RECTANGLE_HH
#define PLATTIS_RECTANGLE_HH

#include "renderer.hh"
#include "camera.hh"

#include <SDL2/SDL.h>

namespace plattis
{

class Rectangle
{
public:
    /// Constructor.
    Rectangle(int x, int y, int w, int h) : m_rect({x, y, w, h}) {}

    /// Draw outline of the rectangle.
    void draw(Renderer& renderer, const Color& color, Camera* camera) 
    { 
        renderer.drawRect(getDestRect(camera), color); 
    }

    // Fill the rendering area with color.
    void fill(Renderer& renderer, const Color& color, Camera* camera) const 
    { 
        renderer.fillRect(getDestRect(camera), color); 
    }

private:
    /// Get destination rectangle based on position and camera.
    /// \param Camera* The game camera.
    /// \return SDL_Rect Destination rectangle.
    SDL_Rect getDestRect(Camera* camera) const;

private:
    SDL_Rect m_rect;
};

}

#endif
