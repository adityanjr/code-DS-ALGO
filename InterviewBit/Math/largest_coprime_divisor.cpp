//  https://www.interviewbit.com/problems/largest-coprime-divisor/

unsigned gcd(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}
int Solution::cpFact(int x, int y) {
    while (gcd(x, y) != 1) {
		x = x / gcd(x, y);
	}
	return x;
}

