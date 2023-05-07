#ifndef PLATTIS_UTIL_HH
#define PLATTIS_UTIL_HH

#include <string>

namespace plattis
{

/// Clamp function.
/// \param value Value to be clamped.
/// \param min Minimum value.
/// \param max Maximum value.
/// \return T& Clamped value.
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

/// Get random integer value from-to values.
/// \param from Minimum value.
/// \param to Maximum value.
/// \return int Random value.
int randomValue(int from, int to);

}

#endif
