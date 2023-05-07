#include "util.hh"

#include <random>

namespace plattis
{

int randomValue(int from, int to)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> dist(from, to);
    return dist(generator);
}

}
