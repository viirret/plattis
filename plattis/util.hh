#ifndef PLATTIS_UTIL_HH
#define PLATTIS_UTIL_HH

#include <charconv>
#include <stdexcept>
#include <string>

namespace plattis
{

template <typename T> struct StringConverter
{
    static T convert(const std::string& str)
    {
        T num;
        auto [p, ec] = std::from_chars(str.data(), str.data() + str.size(), num);
        if (ec != std::errc())
        {
            throw std::invalid_argument("invalid conversion");
        }
        return num;
    }
};

template<typename T>
const T& clamp(const T& value, const T& min, const T& max)
{
    if (value < min)
        return min;
    else if (value > max)
        return max;
    else
        return value;
}

}

#endif
