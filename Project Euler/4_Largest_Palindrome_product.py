#A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
#Find the largest palindrome made from the product of two 3-digit numbers.

min=100
max=999

def max_palindrome():
	largest = 0
	for a in range(max, min-1, -1):
		for b in range(a-1, min-1, -1):
			m = a*b
			if m > largest and str(m) == str(m)[::-1]:
				largest = m
	return largest

print(max_palindrome())