from math import sqrt
import time

N = int(input("Enter the number of primes you would like to calculate: "))

begin = time.time()

primes = [2,3,5,7]

possiblePrime = 11

while len(primes) < N:
  isPrime = 1
  for j in primes:
    if (j*j == possiblePrime) | (j > sqrt(possiblePrime)): break
    if possiblePrime % j == 0:
      isPrime = 0
      break
  if isPrime == 1:
    primes.append(possiblePrime)
  possiblePrime = possiblePrime + 1

end = time.time()

print(primes)

print("\n\nThe time it took to complete this is: "+ str(end-begin))
