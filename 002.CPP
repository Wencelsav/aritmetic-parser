#include "stdafx.h"
#include <iostream>

#include <sstream>

#include <stdlib.h>

using namespace std;



int main()

{

	string str;

	float a, c;

	char b, d;

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

	while (stream >> d)

	{
		if (b == '*')

		{

			stream >> a;

			c = c * a;

		}

		else if (b == '/')

		{

			stream >> a;

			c = c / a;

		}





	}




		cout << c << endl;

}
