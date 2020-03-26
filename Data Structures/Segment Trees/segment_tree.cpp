// [l, r), the right boundary is always excluded
// id = 1, id always starts from 1
// n = number of elements in the array for which the segment tree is built
// allocate 4 * (n + 1) nodes for storing the node data of the segment tree

// the nodes can be custom defined like the one below
struct node {
	int ans, open, closed;
	node(int x, int y, int z) {
		ans = x;
		open = y;
		closed = z;
	}
};

// to use pretty print, overiding the << operator is necessary
ostream& operator <<(ostream& outputStream, const node& p){
	outputStream << "(" << p.ans <<", " << p.open << ", "  << p.closed << ")"; 
	return outputStream;
}

// May need this under strict time limits
#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)

/*------------------- Classic Segment Tree ------------------------*/
void build(int id = 1, int l = 0, int r = n){
	if(l + 1 == r){	//	l + 1 == r
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

/*
 Not to be copied blindly.
 */
void modify(int p, int x, int id = 1, int l = 0, int r = n){
	s[id] += x - a[p];
	if(l + 1 == r){	//	l = r - 1 = p
		a[p] = x;
		return;
	}
	int mid = (l + r)/2;
	if(p < mid)
		modify(p, x, id * 2, l, mid);
	else
		modify(p, x, id * 2 + 1, mid, r);
}

// Used in UVA 12532 - Interval Product
void modify(int p, int x, int id = 1, int l = 0, int r = n){
  if(p < l || p >= r)  return; // Saved from TLE, redues computations
  // by not rebuilding the parts that do not change
  if(l + 1 == r){ //  l = r - 1 = p
    if(l == p)
      s[id] = x; // only update at one point
    return;
  }
  int mid = (l + r)/2;
  // make both the calls, and rebuild the entire table
  modify(p, x, id * 2, l, mid);
  modify(p, x, id * 2 + 1, mid, r);
  s[id] = s[2 * id] * s[2 * id + 1]; /* change '*' to '+' */
}

// to obtain the sum of the query [x, y)
int sum(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id * 2 + 1, mid, r);
}
/*------------------- Lazy Propagation ------------------------*/
// Be careful when setting the lazy values,
// in case some flip or strange operation is present

// This function may change
void upd(int id, int l, int r, int x){// increase all members in this interval by x
	lazy[id] += x; // Be careful, see Ahoy Pirates
	s[id] += (r - l) * x;
}

// no change needed
void shift(int id, int l, int r){// pass update information to the children
	int mid = (l+r)/2;
	upd(id * 2, l, mid, lazy[id]);
	upd(id * 2 + 1, mid, r, lazy[id]);
	lazy[id] = 0;// passing is done
}

// no change needed
void increase(int x, int y, int v, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y){
		upd(id, l, r, v);
		return ;
	}
	// node id is not a leaf node, covered above and hence has 2 children
	shift(id, l, r);
	int mid = (l+r)/2;
	increase(x, y, v, id * 2, l, mid);
	increase(x, y, v, id*2+1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

// to obtain the sum of the query [x, y)
int sum(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return 0; // CAREFUL: return 0/1 for addition/multiplication
	if(x <= l && r <= y)	return s[id];
	shift(id, l, r);
	int mid = (l+r)/2;
	return sum(x, y, id * 2, l, mid) +
	       sum(x, y, id * 2 + 1, mid, r);
}
/*------------------------------------------------------------------*/

// To split an interval to some nodes of this tree
vector<int> s; // s represents the collection of nodes in the tree which covers the interval [x, y)
void split(int x,int y, int id = 1,int l = 0, int r = n){//	id is the index of the node
	if(x >= r or l >= y)	return ;	// in this case, intersect of [l,r) and [x,y) is empty
	if(x <= l && r <= y){
		s.push_back(id); 
		return ;
	}
	int mid = (l+r)/2;
	split(x,y,id * 2,l,mid);
	split(x,y,id * 2 + 1,mid,r);
}
