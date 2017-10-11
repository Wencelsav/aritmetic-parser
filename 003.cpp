#include <iostream>

using namespace std;




double number()

{

	int a = 0;
	for (;;)

	{

		char c = cin.get();
		if ((c >= '0') && (c <= '9'))

		{
			a = a * 10 + (c - '0');
		}
		else

		{

			cin.putback(c);

			return a;

		}

	}

}


double multdiv()

{

	double x = number();

	for (;;)

	{

		char c = cin.get();

		switch (c)

		{

		case '*':

			x = x*number();

			break;

		case '/':

			x = x / number();

			break;

		default:

			cin.putback(c);

			return x;
		}

	}

}




double addsub()

{

	double x = multdiv();
	for (;;)

	{

		char c = cin.get();

		switch (c)

		{

		case '+':

			x = x + multdiv();

			break;

		case '-':

			x = x - multdiv();

			break;

		default:

			cin.putback(c);

			return x;

		}

	}

}







int main()

{

	double a = addsub();

	cout << a << '\n';



}
