#include <list>
#include <iostream>
typedef std::list<int> INTLIST;

int display(const INTLIST& c)
{
int z = 0;
// std::list<int>::const_iterator pos;
// Counter
// Iterator
for( auto pos = c.begin(); pos != c.end(); pos++, z++)
std::cout << *pos << std::endl;
std::cout << std::endl;
return z;
}

int main(){
    std::cout <<"... and miles to go before I sleep." << std::endl;
    std::cout <<"..................................\n\n" << std::endl;
    INTLIST l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(4);
    l1.push_front(5);


    display(l1);
    
    return 0;
}