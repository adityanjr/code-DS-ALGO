#By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
#What is the 10001st prime number?

def nth_prime(n):
	limit = (n * 100) + 1
	
	primes = [True] * limit
	primes[0], primes[1] = [None] * 2
	
	count = 0
	for i,val in enumerate(primes):
		if val is True:
			primes[i*2::i] = [False] * (((limit-1) // i) - 1)
			count += 1
		if count == n:
			return i
	return None

print(nth_prime(10001))