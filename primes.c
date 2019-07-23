#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
    int number;
    int counter =  3;
    int testIfPrime = 7;
    char suffix [3] = { 't', 'h', '\0' };

    printf("c version:\n\nEnter a number and I will tell you which prime number corresponds to it: ");
    scanf("%d", &number);
    printf("*************************************************************************************");
    int* primes = (int *)malloc(sizeof(int) * number);

	clock_t before = clock();  //to test the execution time

    if(number % 10 == 1) {
	suffix[0] = 's';
	suffix[1] = 't';
    } else if(number % 10 == 2) {
	suffix[0] = 'n';
	suffix[1] = 'd';
    } else if(number % 10 == 3) {
	suffix[0] = 'r';
	suffix[1] = 'd';
    }
    
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;

    while(counter < number){
	double sqrtOfTest = sqrt(testIfPrime);
	int binaryValue = 0;
	if( (testIfPrime % 2 == 0) || (testIfPrime % 3 == 0) || (testIfPrime % 5 == 0) ) { binaryValue = 1; }
	for(int k = 0; primes[k] <= sqrtOfTest && binaryValue == 0; k++) {
	    if(testIfPrime % primes[k] == 0) {
		binaryValue = 1;
		break;
	    }
	}
	if(binaryValue == 0) {
	    primes[counter] = testIfPrime;
	    testIfPrime++;
	    counter++;
	} else { testIfPrime++; }
    }

	clock_t difference = clock() - before;

    printf("\nThe %d%s prime number is %d\n", number, suffix, primes[number-1]);
    
    printf("*************************************************************************************");

	printf("\nThe time it took to compute this was %.0f milliseconds\n", (double) difference);

    free(primes);

    printf("*************************************************************************************\n");

    return(0);
}
