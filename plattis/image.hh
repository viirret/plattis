#ifndef PLATTIS_IMAGE_HH
#define PLATTIS_IMAGE_HH

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

namespace plattis
{

class Image
{
public:
    /// Constructor.
    /// \param renderer The SDL renderer.
    /// \param filename The .png filename.
    /// \param x The x position of the image.
    /// \param y The y position of the image.
    Image(SDL_Renderer* renderer, const std::string& filename, float x, float y);

    /// Move constructor.
    /// \param other The object Image.
    Image(Image&& other);

    /// Deleted copy constructor.
    Image(const Image& other) = delete;

    /// Destructor.
    ~Image();

    /// Draw the image.
    void draw(SDL_Renderer* renderer) const;

    /// Change the image size.
    void setScale(float scale);

    virtual float getX() { return m_x; }
    virtual float getY() { return m_y; }

    float m_x;
    float m_y;

protected:

    int m_width;
    int m_height;
    float m_scale = 1.f;

private:
    SDL_Texture* m_texture;
};

}

#endif
