#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main() 
{
    int counter = 3;
    int tester = 7;
    int N = -1;
    char suffix [3] = { 't', 'h', '\0' };

    cout << "c++ version:\n\nEnter a number and I will tell you which prime number corresponds to it: ";
    cin >> N;
    cout << "*************************************************************************************\n";

	clock_t before = clock();  //to test the execution time

    if(N % 10 == 1) {
	suffix[0] = 's';
	suffix[1] = 't';
    } else if(N % 10 == 2) {
	suffix[0] = 'n';
	suffix[1] = 'd';
    } else if(N % 10 == 3) {
	suffix[0] = 'r';
	suffix[1] = 'd';
    }

    int* primes;
    primes = new int[N];
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;

    while(counter < N) {
	double sqrtTESTER = sqrt(tester);
	bool isPrime = true;
	if((tester % 2 == 0) || (tester % 3 == 0) || (tester % 5 == 0)) { isPrime = false; }
	for(int k = 0; primes[k] <= sqrtTESTER && isPrime == true; k++) {
	    if(tester % primes[k] == 0) {
		isPrime = false;
		break;
	    }
	}
	if(isPrime == true) {
	    primes[counter] = tester;
	    tester++;
	    counter++;
	} else { tester++; }
    }

	clock_t difference = clock() - before;

    cout << "The " << N << suffix << " prime number is " << primes[N-1] << endl;

    delete[] primes;

    cout << "*************************************************************************************\n";

	cout << "The time it took to compute this was " << difference << " milliseconds" << endl;

    cout << "*************************************************************************************\n";
}

