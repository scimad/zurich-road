#include <vector>
#include <iostream>

using namespace std;

typedef vector<float> vec_f;
vec_f v1;

//This initialized p1 with ten zeros
vec_f p1(10);

void display(const vec_f& v)
{   
    // Defining 'pos' in following one of the following two ways
    // can also be used to replace the auto keyword

    // vec_f::const_iterator pos;
    // vector<float>::const_iterator pos;
    int cnt = 0;
    for (auto pos = v.begin(); pos<v.end(); pos++, cnt++)
    {
        cout << "Position " << cnt << " -> " << *pos << endl;
    }
}

int main()
{
    cout << "The vector v1 can have max. of "<< v1.max_size() << " elements." << endl;
    cout << "The vector p1 can have max. of "<< p1.max_size() << " elements." << endl;
    p1.push_back(100);
    p1.push_back(200);
    p1.push_back(300);
    p1.push_back(400);

    display(p1);
    return 0;
}