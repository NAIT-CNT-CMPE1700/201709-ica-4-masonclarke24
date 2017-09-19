#include "Bits.h"

//Print out a value as a series of bits
//To a stream
void FPrintBits(FILE* stream, uint value)
{
	//Iterate from msb (bit 31) to lsb (bit 0)
	for (char b = sizeof(value) * 8 - 1; b >= 0; b--)
		//Use and mask -- result will be 0 (false) iff bit is 0
		fprintf(stream, "%c", (value & (1 << b)) ? '1' : '0');
	fflush(stream);
}

//Print out a value as a series of bits to stdout
void PrintBits(uint value)
{
	FPrintBits(stdout, value);
}

//NB: YOU ARE TO COMPLETE THE FUNCTION BELOW
//Count how many 1 bits
byte CountSet(uint val)
{
	byte numberOf1s = 0;
	for (char n = sizeof(val) * 8 - 1; n >= 0; n--)
	{
		if (val & (1 << n))
		{
			numberOf1s++;
		}
	}

	return numberOf1s;
}

//This should work if the function about is correct.
//Count how many 0 bits
byte CountClear(uint val)
{
	return sizeof(val)*8 - CountSet(val);
}

//NB: YOU ARE TO COMPLETE THE FUNCTION BELOW
//Set bit n (bit 0 is lsb)
//Returns the val, modified so bit n is 1
//(If bit n was already 1, it will be unmodified)
uint SetN(uint val, byte n)
{
	val |= 1 << n;
	return val;
}

//NB: YOU ARE TO COMPLETE THE FUNCTION BELOW
//Clear bit n (bit 0 is lsb)
//Returns the val, modified so bit n is 0
//(If bit n was already 0, it will be unmodified)
uint ClearN(uint val, byte n)
{
	val &= ~(1 << n);
	return val;
}

//NB: YOU ARE TO COMPLETE THE FUNCTION BELOW
//Toggle bit n (bit 0 is lsb)
//Returns the val, modified so bit n is different
uint ToggleN(uint val, byte n)
{
	val ^= 1 << n;
	return val;
}