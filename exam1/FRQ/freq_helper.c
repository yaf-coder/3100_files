#include <assert.h>

//TODO
unsigned firstDigit(unsigned k)
{
	unsigned a = k;
	while (a >= 10){
		a /= 10;
	}
	return a;
}//this will repeatedly truncate k by dividing by 10 until there is one digit that remains (the first one) and then will return it.

//TODO
void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{
	for (int i=0; i<n; i++){
		a[i] = firstDigit(a[i]);
	}
	for(int x = 0; x < 10; x++){freq[x] = 0;} // me when the list initializes to 1... I think I sat on this for like 30 mins before realizing this may be the issue.
	for (int j=0; j<n; j++){
		freq[a[j]]++;
	}
}

