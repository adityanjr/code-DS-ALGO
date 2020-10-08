#2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
#What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

import functools

def smallest_multiple(n):
	nums = range(1,n+1)
	primes = []
	for i in nums:
		primes = overlap_list( primes, prime_factors(i) )
	
	return functools.reduce((lambda x,y: x*y), primes)

def overlap_list(orig, factors):
	for i in set(factors):
		add = factors.count(i) - orig.count(i)
		orig.extend([i] * add)
	return orig

def prime_factors(n):
	primfac = []
	d = 2
	while d*d <= n:
		while (n % d) == 0:
			primfac.append(d)
			n //= d
		d += 1
	if n > 1:
	   primfac.append(n)
	return primfac

print(smallest_multiple(20))
