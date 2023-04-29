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
    Image(SDL_Renderer* renderer, const std::string& filename, int x, int y);

    /// Destructor.
    ~Image();

    /// Draw the image.
    void draw(SDL_Renderer* renderer) const;

    /// Change the image size.
    void setScale(float scale);

    /// Set the movement speed.
    void setSpeed(int speed);

public:

    /// Move the image to the left.
    void moveLeft();

    /// Move the image to the right.
    void moveRight();

private:
    int m_speed;
    int m_x;
    int m_y;
    float m_scale = 1.f;

private:
    SDL_Texture* m_texture;
    int m_width;
    int m_height;
};

}

#endif
