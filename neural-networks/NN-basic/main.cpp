#include "perceptron.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Perceptron p;
    std::cout<<p.get_weight()<<std::endl;
    std::cout<<p.get_bias()<<std::endl;
    return 0;
}
