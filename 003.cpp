#include <iostream>
#include <sstream>

	using namespace std;
  
  
	int main()
	{
		
		double a;
		double* b = (double*) new double;
		char* op = (char*) new char;
		string s;
		
		getline(cin, s);
		istringstream stream(s);
		stream >> *b;


		char oper;
		int j = 0;

		while (stream >> oper) {
			switch (oper) {

				case '+':
					if (stream >> a) {
						op = (char*)realloc(op, sizeof(char)*(j + 1));
						*(op + j) = oper;
					}
					j++;
					b = (double*)realloc(b, sizeof(double)*(j + 1) );
					*(b + j) = a;
					break;

				case '-':
					if (stream >> a) {
						op = (char*)realloc(op, sizeof(char)*(j + 1));
						*(op + j) = oper;
					}
					j++;
					b = (double*)realloc(b, sizeof(double)*(j + 1));
					*(b + j) = a;
					break;

				case '*':
					stream >> a;
					*(b + j) = (*(b + j)) * a;
					break;

				case '/':
					stream >> a;
					*(b + j) = (*(b + j)) / a;
					break;
			}
		}

		double res = *b;

		for (int i = 0; i < j + 1; i++) {
			switch (*(op + i)) {
			case '+':
				res += *(b + i + 1); break;
			case '-':
				res -= *(b + i + 1); break;
			}
		}

		cout << res << endl;

		cin.get();
		cin.get();
		return 0;
	}
