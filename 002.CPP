#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

int main()
{
    string str;
    float a, c,d;
    char b;
    getline(cin, str);
    istringstream stream(str);
    stream >> c;
    while (stream >> b)
    {if (b == '*' || b == '/') {
      switch(b) { case '*':
                stream >> b;
                a = a * b;
                break;
            case '/':
                stream >> b;
                a = a / b;
                break;
}
       
    } else if (b == '+' || b == '-') {
  
     switch(b) {
            case '+':
                stream >> b;
                a = a+ b;
                break;
            case '-':
                stream >> b;
                a = a- b;
break;}
       
        

  }cout << d;
}
}
