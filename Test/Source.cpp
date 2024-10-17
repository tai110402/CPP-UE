#include <iostream>
using namespace std;

struct Location
{
    int x;
    Location()
    {
        cout << "Location Constructor" << endl;
    }
    ~Location()
    {
        cout << "Location Destructor" << endl;
    }
};

class Actor
{
public:
   
    Actor()
    {
        cout << "Actor Constructor" << endl;
    }
    ~Actor()
    {
        cout << "Actor Destructor" << endl;
    }
    Location location;
};

int main()
{
    {
        Actor a;
    }
    cout << "tai";
    system("pause");
}