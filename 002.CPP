#include <iostream>
#include <sstream>
#include <stdlib.h>
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
    {if (b == '*' || b == '/') {
      switch(b) { case '*':
                stream >> b;
               c= c * a;
                break;
            case '/':
                stream >> b;
            c = c / a;
                break;
}
       
    } else if (b == '+' || b == '-') {
  
     switch(b) {
            case '+':
                stream >> b;
                c = c + a;
                break;
            case '-':
                stream >> b;
                c = c - a;
break;}
       
        

  }cout << c;
}
}
