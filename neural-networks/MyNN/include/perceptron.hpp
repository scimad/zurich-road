#ifndef _PERCEPTRON
#define _PERCEPTRON

#include "mynn.hpp"
using namespace mynn;

class Perceptron
{
private:
    /* data */
    weight w;
    bias b;
public:
    Perceptron(/* args */);
    ~Perceptron();

    weight get_weight();
    bias get_bias();

};

#endif