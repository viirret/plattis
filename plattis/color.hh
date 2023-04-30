#ifndef PLATTIS_COLOR_HH
#define PLATTIS_COLOR_HH

#include <SDL2/SDL.h>

#include <ostream>
#include <sstream>

namespace plattis
{

class Color
{
public:
    Color() {}

    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : m_r(r), m_g(g), m_b(b), m_a(a) {}

    friend std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        os << "r:" << color.m_r << " g:" << color.m_g << " b:" << color.m_b << " a:" << color.m_a;
        return os;
    }

    std::string getInfo() const
    {
        std::stringstream ss;
        ss << "r:" << m_r << " g:" << m_g << " b:" << m_b << " a:" << m_a;
        return ss.str();
    }

    SDL_Color getSDLColor() const { return {m_r, m_g, m_b, m_a}; }

    void change(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        this->m_r = r;
        this->m_g = g;
        this->m_b = b;
        this->m_a = a;
    }

    void change(const Color& color)
    {
        this->m_r = color.m_r;
        this->m_g = color.m_g;
        this->m_b = color.m_b;
        this->m_a = color.m_a;
    }

    Uint8 getR() const { return m_r; }
    Uint8 getG() const { return m_g; }
    Uint8 getB() const { return m_b; }
    Uint8 getA() const { return m_a; }

private:
    Uint8 m_r, m_g, m_b, m_a;
};

}

#endif
