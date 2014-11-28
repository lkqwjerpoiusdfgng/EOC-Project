// GenValue.h

#ifndef GENVALUE_H
#define GENVALUE_H

#include <cstdlib>
#include <ctime>
using namespace std;

/**********************************************************
To seed the Random Generator rand()

Execute srand() in application.

srand( static_cast<int>( time(NULL) ));

RAND_MAX is maximum unsigned integer value generated.
RAND_MAX == 32767
**********************************************************/

int GenValue(int L, int H)
{
	return L + rand() % (H - L + 1);
}

#endif