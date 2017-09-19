#include "Bits.h";
typedef unsigned int uint;
typedef unsigned char byte;

int main(int argc, char** argv)
{
	//NB: Your task is to implement the unfinished routines in
	//Bits.c.  You'll need to add to the code below in order to 
	//test your functions.  For checkoff, you will be provided with
	//a new main that will test that your implementation of the 
	//functions works properly.

	//for (uint u = 0; u < 256; ++u)
	//{
	//	PrintBits(u);
	//	printf("\n");
	//	printf(u);
	//	printf("\n");
	//}


	PrintBits(ClearN(255, 1));
	//Pause display only while debugging
#ifdef _DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
	printf("Press Enter to Exit");
	fgetc(stdin);
#endif

	return 0;
}