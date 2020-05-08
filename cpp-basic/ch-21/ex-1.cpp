#include <iostream>
int main(int argc, char const *argv[])
{
    double* d_ptr = new double(3.14159);
    std::cout<<*d_ptr<<std::endl;

    delete d_ptr;

    //Assigning a reference name to a pointer location
    double& d = *d_ptr;
    d = 2.718281828;
    std::cout<<d<<std::endl;

    *d_ptr = 1.51;
    std::cout<<d<<std::endl;
    return 0;
}
