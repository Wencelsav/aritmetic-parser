include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
#include "Windows.h"
 
void eatspaces(char* str); //функция для удаления пробелов
double expr(char* str); //функция, вычисляющая выражение
double term(char* str, int& index); //функция для анализа элемента
double trigon(char* str, int& index); //функция для вычисления тригонометрических значений
double power(char* str, int& index); //функция для извлечения степени
double number(char* str, int& index); //функция, распознающая число
char* extract(char* str, int& index); //функция для извлечения подстроки
 
const int MAX = 80; //максимальный размер буфера
 
int main()
    {
    setlocale(0, "Russian");
    char buffer[MAX] = {0}; //область хранения вычисляемого входного выражения
    cout << endl << "Добро пожаловать в дружественный колькулятор!" << endl
         << "Введите выражение или пустую строку для завершения." << endl;
    for ( ; ; )
        {
        cin.getline(buffer, sizeof buffer); //читаем входную строку
        eatspaces(buffer); //удаляем все пробелы из строки
        if (!buffer[0]) //если пустая строка
            return 0;
        cout << "= " << expr(buffer)
             << endl << endl;
        }
    }
        
void eatspaces(char* str)
    {
    int i = 0;                          //индекс места в строке "куда копировать"
    int j = 0;                          //индекс места в строке "откуда копировать"
    while ((*(str+i) = *(str + j++)) != '\0') //цикл, пока очередной символ не '\0'
        if (*(str+i) != ' ')  //увеличиваем i, если символ не пробел
            i++;
    return;
    }
    
double expr(char* str)
    {
    double value = 0.0;         //здесь сохраняем результат
    int index = 0;              //текущая позиция символа
    value = term(str, index);   //получить первый элемент
    for ( ; ; )                 //бесконечный цикл, выход внутри
        {
        switch (*(str+index++)) //выбрать действие на основе текущего символа
            {
            case '\0':          //конец строки, возвращаем значение
                return value;
            case '+':           //знак плюс, прибавляем элемент к value
                value += term(str, index);
                break;
            case '-':           //знак минус, вычитаем элемент из value
                value -= term(str, index);
                break;
            default:            //все остальное не котируется
                int i = index;
                while (--i > 0)
                    cout << " ";
                cout << "^" << endl;
                cout << "Эй, повнимательней можно?! Здесь обнаружена ошибка. " << endl;
                exit(1);
            }
        }
    }
    
double term(char* str, int& index)
    {
    double value = 0.0;             //здесь накапливается значение результата
    value = power(str, index);      //получить первое число элемента
    //выполняем цикл до тех пор, пока имеем допустимую операцию
    while ((*(str + index) == '*') || (*(str + index) == '/')) 
        {
        if (*(str+index) == '*')
            value *= power(str, ++index);
        if (*(str+index) == '/')
            value /= power(str, ++index);
        }
    return value;
    }
    
    
double power(char* str, int& index)
    {
    double value = 0.0;
    value = trigon(str, index);
    while (*(str + index) == '^')
        {
        value = pow(value, trigon(str, ++index)); //возводим в степень
        }
    return value;
    }   
 
double trigon(char* str, int& index)
    {
    int buf_index = 0;
    int temp_index = index; //переменная для хранения индекса (чтобы если что вернуть индекс без изменений)
    char* p_str = 0;    //временный указатель для сравнения символов
    double value = 0;
    while (isalpha(*(str + temp_index)))
        {
        buf_index++;    //сколько букв
        temp_index++;   //текущий индекс
        }
    if (!buf_index)     //если нет ни одной буквы, то возвращаем число
        {
        value = number(str, index);
        return value;
        }
    else                //иначе смотрим, являются ли буквы чем-нибудь этим
        {
        p_str = new char[buf_index+1];  //а для этого создаем временную строку, чтобы сравнить
        p_str[buf_index] = '\0';
        strncpy(p_str, str+index, buf_index);
        }
    if (strcmp(p_str, "sin") == 0)      //синус в градусах
        {
        value = sin(3.141592/180*number(str, temp_index));
        index = temp_index;
        delete[] p_str;     //не забываем удалить временную строку
        return value;
        }
    else if (strcmp(p_str, "cos") == 0) //косинус в градусах
        {
        value = cos(3.141592/180*number(str, temp_index));
        index = temp_index;
        delete[] p_str;     //не забываем удалить временную строку
        return value;
        }
    else if (strcmp(p_str, "tan") == 0) //тангенс в градусах
        {
        value = tan(3.141592/180*number(str, temp_index));
        index = temp_index;
        delete[] p_str;     //не забываем удалить временную строку
        return value;
        }
    else
        {
        return value;
        }
    }
    
double number(char* str, int& index)
    {
    double value = 0.0;                 //хранит результирующее значение
    if (*(str + index) == '(')
        {
        char* p_substr = 0;
        p_substr = extract(str, ++index);
        value = expr(p_substr);
        delete[] p_substr;
        return value;
        }
    //продуманский цикл, превращает символы в число
    while (isdigit(*(str+index)))       //цикл накапливает ведущие цифры 
        value = 10*value + (*(str + index++) - '0');
    if (*(str + index) != '.')          //если не цифра, проверяем на десятичную точку
        return value;
    double factor = 1.0;                //множитель для десятичных разрядов
    //еще один продуманский цикл, возвращает десятичную часть
    while (isdigit(*(str + (++index)))) //выполнять цикл, пока идут цифры 
        {
        factor *= 0.1;
        value = value + (*(str + index) - '0')* factor;
        }
    return value;
    }
    
char* extract(char* str, int& index)
    {
    char buffer[MAX];       //временное пространство для подстроки
    char* p_str = 0;        //указатель на новую строку для возврата
    int numL = 0;           //счетчик найденных левых скобок
    int buf_index = index;  //сохранить начальное значение index
    do
        {
        buffer[index - buf_index] = *(str+index); //копируем символ текущей строки в подстроку
        switch(buffer[index - buf_index]) //смотрим, чо это за символ
            {
            case ')':
                if (numL == 0)
                    {
                    buffer[index - buf_index] = '\0'; //если счетчик скобочек верный, ставим символ конца строки
                    ++index;    //устанавливаем индекс на следующий за скобочкой элемент
                    p_str = new char[index-buf_index];
                    if (!p_str)
                        {
                        cout << "Выделение памяти не удалось, программа прервана.";
                        exit(1);
                        }
                    strcpy_s(p_str, index - buf_index, buffer); //и копируем подстроку в новую память
                    return p_str;
                    }
                else
                    numL--;     //уменьшаем счетчик скобок
                break;
            case '(':
                numL++;         //соответственно увеличиваем
                break;
            }
        } while (*(str + index++) != '\0');     //устанавливаем индекс в следующий элемент
    cout << "Вывод за пределы выражения, возможно, плохой ввод." << endl;
    exit(1);
    return p_str;
    }
