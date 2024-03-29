// Programmer Name: Marco Seman
// CIS 310
// Professor Name: David Yoon
// Program # 0


#include "stdafx.h"
#include <iostream>
#include <math.h> 
using namespace std;

// class that converts decimal to binary
class binary
{
private:
	int bin;

public:
	binary()
	{
		bin = 0;
	}

	void setBinary(int b)
	{
		int rem;

		// couts the number if its less than or equal to 1
		if (b <= 1)
		{
			cout << b;
			return;
		}

		rem = b % 2;  // module the user's entry by 2
		setBinary(b >> 1); // repeat the set binary sequence until b(decimal entered) is 0 
		cout << rem;
	}
};

// convert decimal to hexidecimal
class hexidecimal
{
private:
	int hex;
	int k;
public:
	hexidecimal()
	{
		hex = 0;
	}

	// when user enters decimal (h) convert that decimal here
	void setHex(int h)
	{
		// "a" is only used as a temparary storage for the remaining int
		// num is the remainder
		int num, a; 
		/*
		// 4096 through 65536
		if (h >= 4096 && h < 65536)
		{
			a = h % 4096; // remainder for 4096
			num = floor(h / 4096); // round to the lowest whole int
			if (num > 9) // if the number is between 9 and 15, it prints the character
			{
				switch (num)
				{
				case 10: cout << "A"; break;
				case 11: cout << "B"; break;
				case 12: cout << "C"; break;
				case 13: cout << "D"; break;
				case 14: cout << "E"; break;
				case 15: cout << "F"; break;
				}
			}
			// if it's less than 9
			else
			{
				cout << num; 
			}
			// place the module of 4096 in h to be used in the next sequence
			h = a;
		}
		// always cout "0" in case it passes through this sequence
		else
		{
			cout << "0";
		}

		// 256 through 4096
		if (h >= 256 && h < 4096)
		{
			a = h % 256; // remainder of 256
			num = floor(h / 256); // round to the lowest int
			if (num > 9) // same as before
			{
				switch (num)
				{
				case 10: cout << "A"; break;
				case 11: cout << "B"; break;
				case 12: cout << "C"; break;
				case 13: cout << "D"; break;
				case 14: cout << "E"; break;
				case 15: cout << "F"; break;
				}
			}
			else
			{
				cout << num; 
			}
			// place the module of 256 in h
			h = a;
		}
		// place a 0 in case it skips this sequence
		else
		{
			cout << "0";
		}
		*/
		// 16 through 255
		if (h >= 16 && h < 256)
		{
			a = h % 16; // remainder of 16
			num = floor(h / 16); // round to the lowest int
			if (num > 9)
			{
				switch (num)
				{
				case 10: cout << "A"; break;
				case 11: cout << "B"; break;
				case 12: cout << "C"; break;
				case 13: cout << "D"; break;
				case 14: cout << "E"; break;
				case 15: cout << "F"; break;
				}
			}
			else
			{
				cout << num;
			}
			// place the remainder of 16 back into h
			h = a;
		}
		// print the 0 incase it skips this sequence
		else 
		{
			cout << "0";
		}
		
		// 0 through 15
		
		if (h > 0 && h < 16)
		{
			num = h % 16;

			if (num > 9)
			{
				switch (num)
				{
				case 10: cout << "A"; break;
				case 11: cout << "B"; break;
				case 12: cout << "C"; break;
				case 13: cout << "D"; break;
				case 14: cout << "E"; break;
				case 15: cout << "F"; break;
				}
			}
			else
			{
				cout << h;
			}
		}
		else
		{
			cout << "0";
		}
	}

};

// convert decimal to bcd
class BCD : public binary
{
private:
	int bcd;

public:
	BCD()
	{
		bcd = 0;
	}
	// convert decimal to BCD 1 - 255
	void setBCD(int B)
	{
		// s = single digit, d = double digit, t = triple digit
		int s, d, t;
		
			t = floor(B / 100);
			d = floor(B / 10);
			d = d % 10;
			s = B % 10;
			d = (B / 10) % 10;

			switch (t)
			{
			case 0: cout << "0000 "; break;
			case 1: cout << "0001 "; break;
			case 2: cout << "0010 "; break;
		}
			switch (d)
			{
			case 0: cout << "0000 "; break;
			case 1: cout << "0001 "; break;
			case 2: cout << "0010 "; break;
			case 3: cout << "0011 "; break;
			case 4: cout << "0100 "; break;
			case 5: cout << "0101 "; break;
			case 6: cout << "0110 "; break;
			case 7: cout << "0111 "; break;
			case 8: cout << "1000 "; break;
			case 9: cout << "1001 "; break;
			}

			switch (s)
			{
			case 0: cout << "0000 "; break;
			case 1: cout << "0001 "; break;
			case 2: cout << "0010 "; break;
			case 3: cout << "0011 "; break;
			case 4: cout << "0100 "; break;
			case 5: cout << "0101 "; break;
			case 6: cout << "0110 "; break;
			case 7: cout << "0111 "; break;
			case 8: cout << "1000 "; break;
			case 9: cout << "1001 "; break;
			}

		bcd = B;
	}
};

int main()
{
	// Wasn't sure what you wanted. the commented out section will compute a number writen by the user

	/*
	int decimal;
	cout << "Enter a number to convert to Binary, Hexidecimal, and BCD" << endl;
	cin >> decimal;

	while (decimal < 0 || decimal > 255)
	{
		if (decimal < 0 || decimal > 255)
		{
			cout << "Enter a value between 0 and 255" << endl;
			cin >> decimal;
		}
	}
	*/

	binary b;
	hexidecimal h;
	BCD d;

	/*
	cout << "Value for Binary: ";
	b.setBinary(decimal);
	cout << endl << endl;

	cout << "Value for Hexidecimal: ";
	h.setHex(decimal);
	cout << endl << endl;

	cout << "Value for BCD: ";
	d.setBCD(decimal);
	cout << endl;
	*/

	cout << "Decimal     Binary	    Hexidecimal	  BCD" << endl;

	int decimal = 0;
	// a loop that ends after 255
	while (decimal <= 255)
	{
	cout << decimal << "           ";
	b.setBinary(decimal);
	cout << "               ";
	h.setHex(decimal);
	cout << "             ";
	d.setBCD(decimal);
	cout << endl;
	decimal++;
	}

	return 0;
}