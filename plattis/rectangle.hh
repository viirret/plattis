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
    /// \param x The x position of the rectangle.
    /// \param y The y position of the rectangle.
    /// \param w The width of the rectangle.
    /// \param h The height of the rectangle.
    Rectangle(int x, int y, int w, int h) : m_rect({x, y, w, h}) {}

    /// Move constructor.
    /// \param other The other rectangle.
    Rectangle(Rectangle&& other) : m_rect(other.m_rect) {}

    /// Draw outline of the rectangle.
    /// \param renderer Our renderer object.
    /// \param color The drawing color.
    /// \param camera Our camera object.
    void draw(Renderer& renderer, const Color& color, Camera* camera) 
    { 
        renderer.drawRect(getDestRect(camera), color); 
    }

    // Fill the rendering area with color.
    // \param renderer Our renderer object.
    // \param color The drawing color.
    // \param camera The camera object.
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
