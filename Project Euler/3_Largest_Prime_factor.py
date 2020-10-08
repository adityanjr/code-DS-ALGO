#The prime factors of 13195 are 5, 7, 13 and 29.
#What is the largest prime factor of the number 600851475143 ?

from math import sqrt

def largest_prime_factor(number):
	for i in range(2, int(sqrt(number))):
		if number % i == 0:
			return largest_prime_factor(number / i)
	return number

print(largest_prime_factor(600851475143))