#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string str;
    float a, c;
    char b;
    getline(cin, str);
    istringstream stream(str);
    stream >> c;
    while (stream >> b)
    {
        if (b == '+')
        {
            stream >> a;
            c = c + a;
        }
        else if (b == '-')
        {
            stream >> a;
            c = c - a;
        }
    }
     
    cout << c;
    return 0;

}
