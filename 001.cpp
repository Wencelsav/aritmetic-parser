#include <iostream>

using namespace std;

int main() {

	int x, y;
	char a, b;
	cin >> x >> a;
	if ((a == '>') || (a == '<')) {cin >> b >> y;}
	else { cin >> y; }
	if (a == '+') {	cout << x + y;	}
	else if (a == '-') {cout << x - y;}
	else if (a == '*') {cout << x*y;}
	else if (a == '/') {cout << (double)x / y;}
	else if (a == '%') {cout << x%y;}
	else if (a == '&') {cout << (x & y);}
	else if (a == '|') {cout << (x | y);}
	else if (a == '^') {cout << (x^y);}
	else if ((a == '<') && (b == a)) {cout << (x << y);}
	else if ((a == '>') && (b == a)) {cout << (x >> y);}
	else { cout << "wrong formula"; }

	cin.get();

	return 0;

}
