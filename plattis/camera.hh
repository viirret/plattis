#ifndef PLATTIS_CAMERA_HH
#define PLATTIS_CAMERA_HH

namespace plattis
{

class Camera
{
public:
    Camera(int screenWidth, int screenHeight)
        : m_screenWidth(screenWidth), m_screenHeight(screenHeight)
    {
    }

    void setPosition(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

    float getX() { return m_x; }
    float getY() { return m_y; }

    int getWidth() { return m_screenWidth; }
    int getHeight() { return m_screenHeight; }

private:
    float m_x, m_y;
    int m_screenWidth, m_screenHeight;
};

}

#endif
