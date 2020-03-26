vi s; // the segment tree for range maximum query
int n;

void modify(int p, ll x, int id = 1, int l = 0, int r = n){
	if(r == l + 1){	//	l = r - 1 = p
		s[id] = max(s[id], x);
		return;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid); // go left
	else 
		modify(p, x, id * 2 + 1, mid, r); // go right
	s[id] = max(s[2 * id], s[2 * id + 1]);
}

ll rmq(int x, int y, int id = 1, int l = 0, int r = n){
	if(r <= x or l >= y)	return -1;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return max(rmq(x, y, id * 2, l, mid),
	           rmq(x, y, id * 2 + 1, mid, r));
}

void init_segment_tree() {
	n = 1E5 + 5;
	s.assign(4 * 1E5 + 20, -1);
}