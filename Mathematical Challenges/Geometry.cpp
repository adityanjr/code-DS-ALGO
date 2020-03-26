struct fraction {
	int numerator, denominator;
	fraction() : numerator(0), denominator(1) {}
	fraction(int n, int d) {
		numerator = n;
		denominator = d;
		int g = __gcd(n, d);
		numerator /= g;
		denominator /= g;
	}
};

struct point {
	ll x, y;
	point() : x(0), y(0) {}
	point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator<(const point &p) const {
		if(x != p.x) return x < p.x;
		return y  < p.y;
	}
	bool operator==(const point &p) const {
		return p.x == x and p.y == y;
	}
	bool operator!=(const point &p) const {
		return p.x != x or p.y != y;
	}
	friend ostream& operator<<(ostream &stream, const point &p) {
		return stream << "[" << p.x << ", " << p.y << "]";
	}
};

struct line {
	ll a, b, c;
	line() : a(0), b(0), c(0) {}
	line(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}
	bool contains(const point& p) {
		return (a*p.x + b*p.y + c) == 0;
	}
	bool operator<(const line &l) const {
		if(a != l.a) return a < l.a;
		if(b != l.b) return b < l.b;
		return c < l.c;
	}
	bool operator!=(const line &l) const {
		return l.a != a or l.b != b or l.c != c;
	}
	bool operator==(const line &l) const {
		return l.a == a and l.b == b and l.c == c;
	}
	friend ostream& operator<<(ostream &stream, const line &l) {
		return stream << "[" << l.a << ", " << l.b << ", " << l.c << "]";
	}
};

line get_line(const point &p1, const point &p2) {
	ll del_x = p2.x - p1.x;
	ll del_y = p2.y - p1.y;
	ll a, b, c, gcd;
	a = del_x;
	b = -del_y;
	c = p1.y * del_x - p1.x * del_y;
	gcd = __gcd(__gcd(a, b), c);
	a /= gcd; b /= gcd; c /= gcd;
	return line(a, b, c);
}

ll get_length(const point &p1, const point &p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool are_perpendicular(const line &l1, const line &l2) {
	return (l1.a * l2.a + l1.b * l2.b) == 0;
}