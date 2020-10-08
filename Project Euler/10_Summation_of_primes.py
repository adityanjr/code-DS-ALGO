#The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#Find the sum of all the primes below two million.

size = 2000000
is_prime = [True for i in range(size)]

for i in range(2, size):
	if is_prime[i]:
		j = 2
		while i * j < size:
			is_prime[i * j] = False
			j += 1

print(sum(filter(lambda x: is_prime[x], range(2, size))))