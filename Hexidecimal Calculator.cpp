// Programmer Name: Marco Seman
// CIS 310 Program #4
// Professor Name: David Yoon
// Due Date: April 4, 2018
// Description:
// user must enter a numeric or hexidecimal value
// followed by a space, operand, space, numeric value
// so it should look like this 1 + 1
// result outputs 1+1=2

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// addition part
int Addition(int x, int y)
{
	// keep going until 0
	while (y != 0)
	{
		// carry = common 
		// store the x and y bits
		int carry = x & y;

		// result of the bit, have y not set
		x = x ^ y;

		// shift carry by one, to give x the sum
		y = carry << 1;
	}
	return x;
}

// subtraction part
int subtract(long x, long y)
{
	if (y == 0)
	{
		return x;
	}

	int sub = x ^ y,

		subCarry = (sub & y) << 1;
	return subtract(sub, subCarry);
}

// multiply part
int multiply(int x, int y)
{
	int val = 0;
	while (y--)
	{
		val = Addition(val, x);
	}

	return val;
}

// module part
int power(int x, int y)
{
	int val = 1;
	while (y--)
	{
		val = multiply(val, x);
	}

	return val;
}

// division part
vector<int> division(int x, int y)
{
	// use a vector to store the values of quotient and remainder
	vector<int> ans;

	int i = x;
	int quotient = 0;

	while (i >= y)
	{
		i = i - y;
		quotient++;
	}

	int result = i;

	ans.push_back(quotient);
	ans.push_back(result);

	return ans;
}

int main()
{
	char operand;
	string value1;
	string value2;

	cin >> value1; // first value
	cin >> operand; // the user will input either '+', '-', '*', '/', '$'
	cin >> value2;

	// set values of x and y
	unsigned int x, y;

	// stringstream 4 values
	stringstream ss, ss1, ss2, ss3;

	// this converts strings into value for A - F
	ss1 << hex << value1; 
	ss2 << hex << value2;

	// set whatever is in stringstream x and y to ss1 and ss2
	ss1 >> x;
	ss2 >> y;

	// addition
	if (operand == '+')
	{
		// forward the results to addition
		int result = Addition(x, y);

		// take the hexidecimals to results
		ss << hex << result;
		string answer = ss.str();

		// converts values corrently
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		cout << value1 << operand << value2 << "= ";
		cout << answer << endl;
	}

	// subtraction
	else if (operand == '-')
	{
		// do the same as what I did in addition
		long result = subtract(x, y);
		ss << hex << result;
		string answer = ss.str();
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		cout << value1 << operand << value2 << "= ";
		cout << answer << endl;
	}

	// multiplication
	else if (operand == '*')
	{
		// same as the previous
		int result = multiply(x, y);
		ss << hex << result;
		string answer = ss.str();
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		cout << value1 << operand << value2 << "= ";
		cout << answer << endl;
	}

	// module
	else if (operand == '$')
	{
		int result = power(x, y);
		ss << hex << result;
		string answer = ss.str();
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		cout << value1 << operand << value2 << "= ";
		cout << answer << endl;
	}

	// division
	else if (operand == '/')
	{
		vector<int> sol;
		sol = division(x, y);

		int q = sol[0];
		ss << hex << q;
		string res = ss.str();
		cout << value1 << operand << value2 << "= ";
		cout << "quotient " << res;

		int r = sol[1];
		ss3 << hex << r;
		string res1 = ss3.str();
		transform(res.begin(), res.end(), res.begin(), ::toupper);
		cout << ", remainder " << res1 << endl;

	}

}