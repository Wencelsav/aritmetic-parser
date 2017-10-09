#include <iostream>
#include <iomanip>
 
double number();
double factor();
double expr();
using namespace std;

int main()
{
    double n;
 
    setlocale(LC_ALL, "Rus");
 
    cout << "Введите выражение: ";
 
    n = expr();
 
    cout << "Результат вычисления: " << setprecision(8) << n << endl;
 
    cin.get();
    return 0;
}
 
double number()
{
    double result = 0.0;
    double k = 10.0;
    int sign = 1;
    char c;
 
    c = cin.get();
 
    while (c == ' ')
        c = cin.get();
 
    if (c == '-')
        sign = -1;
    else
        cin.putback(c);
 
    while (true)
    {
        c = cin.get();
 
        while (c == ' ')
            c = cin.get();
 
        if (c >= '0' && c <= '9')
            result = result * 10.0 + (c - '0');
        else
        {
            cin.putback(c);
            break;
        }
    }
 
    c = cin.get();

    return sign * result;
}
 
double factor()
{
    double result = brackets();
    double temp;
    char c;
 
    while (true)
    {
        c = cin.get();
 
        while (c == ' ')
            c = cin.get();
 
        switch (c)
        {
        case '*':
            result *= brackets();
            break;
        case '/':
            temp = brackets();
 
            if (temp == 0.0)
            {
                cout << "Деление на нуль!" << std::endl;
                exit(-1);
            }
 
            result /= temp;
            break;
        default:
            cin.putback(c);
            return result;
        }
    }
}
 
double expr()
{
    double result = factor();
    char c;
 
    while (true)
    {
        c = cin.get();
 
        while (c == ' ')
            c = cin.get();
 
        switch (c)
        {
        case '+':
            result += factor();
            break;
        case '-':
            result -= factor();
            break;
        default:
            cin.putback(c);
            return result;
        }
    }
}
