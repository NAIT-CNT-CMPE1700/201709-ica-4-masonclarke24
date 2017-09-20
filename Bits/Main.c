#include "Bits.h"
#include <assert.h> //for assert()
#include <math.h> //For pow()
typedef unsigned int uint;
typedef unsigned char byte;

int main(int argc, char** argv)
{
	//This is the test code.  Replace your main.c contents with 
	//this and ask for checkoff if you pass the test.  No edits!
	//However, if you get an error, the line where the error 
	//occurs should tell you all that you need to know.

	uint u = 0; //General scratch test value if needed.
	uint v = 0; //Ditto

				//Counting bits tests
	assert(CountSet(0xAAAAAAAA) == CountClear(0xAAAAAAAA));
	assert(CountSet(0x55555555) == CountClear(0xAAAAAAAA));
	assert(CountClear(0x55555555) == CountSet(0xAAAAAAAA));
	assert(CountSet(0) == 0);
	assert(CountClear(0) == 32);
	assert(CountSet(0xFFFFFFFF) == 32);
	assert(CountClear(0xFFFFFFFF) == 0);
	assert(CountSet(0x80000001) == 2);
	assert(CountClear(0xFFFE7FFF) == 2);
	assert(CountSet(0xF0F0F0F0) == 16);
	assert(CountClear(0x0F0F0F0F) == 16);

	//SetN
	assert(SetN(SetN(0, 31), 0) == 0x80000001); //Chaining
	u = 0;
	for (char c = 0; c < 32; ++c)
	{
		assert(SetN(0, c) == (uint)pow(2, c)); // Bit c is 2 to the c.
		u = SetN(u, c); //Set one of the bits
	}
	//All of u's bits should be set now
	assert(u == 0xFFFFFFFF);

	//ClearN
	assert(ClearN(ClearN(0xFFFFFFFF, 0), 31) == 0x7FFFFFFE); //Chaining
	for (char c = 0; c < 32; ++c)
	{
		assert(ClearN(0xFFFFFFFF, c) == 0xFFFFFFFF - (uint)pow(2, c)); // Bit c is 2 to the c.
		u = ClearN(u, c); //Clear one of the bits
	}
	//All of u's bits should be cleared now
	assert(u == 0);

	//ToggleN
	assert(ToggleN(ToggleN(0xFFFFFFFF, 0), 31) == 0x7FFFFFFE); //Chaining
	assert(ToggleN(ToggleN(0, 31), 0) == 0x80000001); //Chaining
	v = 0xFFFFFFFF;
	for (char c = 0; c < 32; ++c)
	{

		assert(ToggleN(0, c) == (uint)pow(2, c)); // Bit c is 2 to the c.
		assert(ToggleN(0xFFFFFFFF, c) == 0xFFFFFFFF - (uint)pow(2, c)); // Bit c is 2 to the c.
		u = ToggleN(u, c); //Set one of the bits
		v = ToggleN(v, c); //Clear one of the bits
	}
	//All of u and v's bits should be changed now
	assert(u == 0xFFFFFFFF);
	assert(v == 0);


	//Pause display only while debugging
#ifdef _DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
	printf("-------------------------------------------------------\n");
	printf("If you got here, your program meets expectations.  Yay!\n");
	printf("-------------------------------------------------------\n");
	printf("             Press Enter to Exit:");
	fgetc(stdin);
#endif

	return 0;
}