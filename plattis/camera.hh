#ifndef PLATTIS_CAMERA_HH
#define PLATTIS_CAMERA_HH

#include <box2d/box2d.h>

#include <algorithm>

namespace plattis
{

class Camera
{
public:
    /// Constructor.
    Camera(int screenWidth, int screenHeight)
        : m_screenWidth(screenWidth), m_screenHeight(screenHeight)
    {
    }

    /// Set the x and y position of the camera.
    /// \param x The x position.
    /// \param y The y position.
    void setPosition(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    /// Convert world position the screen position.
    /// \param worldPos The position in world coordinates.
    /// \return The position in screen coordinates.
    b2Vec2 ConvertWorldToScreen(const b2Vec2& worldPos)
    {
        // Calculate the screen position based on the camera position and the world position.
        float screenX = (static_cast<float>(worldPos.x) - m_x) * m_pixelsPerMeter;
        float screenY = (static_cast<float>(worldPos.y) - m_y) * m_pixelsPerMeter;

        // Invert the Y-axis to match the screen coordinates.
        screenY = static_cast<float>(m_screenHeight) - screenY;

        // Return the screen position as a b2Vec2.
        return b2Vec2(static_cast<int>(screenX), static_cast<int>(screenY));
    }

    /// Set the x position of the camera.
    /// \param x The x position.
    void setX(float x) { m_x = x; }

    /// Set the y position of the camera.
    /// \param y The y position.
    void setY(float y) { m_y = y; }

    /// Get the x position of the camera.
    /// \return float The x position of the camera.
    float getX() { return m_x; }

    /// Get the y position of the camera.
    /// \return float The y position of the camera.
    float getY() { return m_y; }

    /// Get the width of the screen.
    /// \return int The width of the screen.
    int getWidth() { return m_screenWidth; }

    /// Get the height of the screen.
    /// \return int The height of the screen.
    int getHeight() { return m_screenHeight; }

private:
    float m_x, m_y;
    int m_screenWidth, m_screenHeight;
    float m_pixelsPerMeter = std::min(static_cast<float>(m_screenWidth) / 10.0f, static_cast<float>(m_screenHeight) / 5.0f);
};

}

#endif
