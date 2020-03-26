// build usual segment tree
#define M ((L+R)/2)
int st[4*n];
void build(int arr[], int p=1, int L=0, int R=n-1) {
    if (L == R) st[p] = arr[L]; // construct as leaf
    else { // construct as parent
        build(arr, 2*p, L, M);
        build(arr, 2*p+1, M+1, R);
        st[p] = st[2*p] + st[2*p+1];
    }
}

// build persistent segment tree
#define M ((L+R)/2)
int build(int arr[], int L=0, int R=n-1) {
    if (L == R) return newleaf(arr[L]); // construct as leaf
    else return newparent(build(arr, L, M), build(arr, M+1, R)); // construct as parent
}
// Usage: int root = build(arr, 0, n - 1);
const int N = 10000;
const int SIZE = 8 * N * ceil(log(N));

int l[SIZE], r[SIZE], st[SIZE], NODES = 0;
int newleaf(int value) {
    int p = ++NODES;
    l[p] = r[p] = 0; // null
    st[p] = value;
    return p;
}
int newparent(int lef, int rig) {
    int p = ++NODES;
    l[p] = lef;
    r[p] = rig;
    st[p] = st[lef] + st[rig]; // immediately update value from children
    return p;
}

// Point Update (usual segment tree)
void update(int i, int x, int p=1, int L=0, int R=n-1) {
    if (L == R) {st[p] = x; return;}
    if (i <= M) update(i, x, 2*p, L, M);
    else update(i, x, 2*p+1, M+1, R);
    st[p] = st[2*p] + st[2*p+1];
}

// Point Update (persistent segment tree)
// return an int, a pointer to the new root of the tree
int update(int i, int x, int p, int L=0, int R=n-1) {
    if (L == R) return newleaf(st[p] + x);
    if (i <= M) return newparent(update(i, x, l[p], L, M), r[p]);
    else        return newparent(l[p], update(i, x, r[p], M + 1, R));
}

// Usage:
// int new_version_root = update(i, x, root);
// Both roots are valid, you can query from both of them!

/*
 * Bonus: Range Copy (persistent segment tree)
 */
// revert range [a:b] of p
int rangecopy(int a, int b, int p, int revert, int L=0, int R=n-1) {
    if (b < L || R < a) return p; // keep version
    if (a <= L && R <= b) return revert; // reverted version
    return newparent(rangecopy(a, b, l[p], l[revert], L, M),
                     rangecopy(a, b, r[p], r[revert], M+1, R));
}

// Usage: (revert a range [a:b] back to an old version)
// int reverted_root = rangecopy(a, b, root, old_version_root);

/*
 * Persistent Lazy Propagation
 */

bool hasflag[]; // if node has a flag (sometimes, you can omit this)
int flag[];     // the actual value of the flag

// returns a new node with a lazy flag
int newlazykid(int node, int delta, int L, int R);

void propagate(int p, int L, int R) {
    if (hasflag[p]) {
        if (L != R) { // spread the laziness
            l[p] = newlazykid(l[p], flag[p], L, M);
            r[p] = newlazykid(r[p], flag[p], M + 1, R);
        }
        // reset flag
        hasflag[p] = false;
    }
}

int newlazykid(int node, int delta, int L, int R) {
    int p = ++NODES;
    l[p] = l[node];
    r[p] = r[node];
    flag[p] = flag[node]; // need this since lazy kid might be lazy before
    hasflag[p] = true;

    /* range increase */
    flag[p] += delta;
    st[p] = st[node] + (R - L + 1) * delta;
    /* edit depending on the problem */

    return p;
}

// Lazy Range Update
// range update on [a:b] with value x, on the tree rooted at p
int update(int a, int b, int x, int p, int L=0, int R=n-1) {
    if (b < L || R < a)   return p;
    if (a <= L && R <= b) return newlazykid(p, x, L, R); 
    propagate(p, L, R); // always do this before going down
    return newparent(update(a, b, l[p], x, L, M),
                     update(a, b, r[p], x, M + 1, R));
}

// Lazy Range Query
// range query on [a:b], on the tree rooted at p
int query(int a, int b, int p, int L=0, int R=n-1) {
    if (b < L || R < a)   return 0;
    if (a <= L && R <= b) return st[p];
    propagate(p, L, R); // always do this before going down
    return query(a, b, l[p], x, L, M) + query(a, b, r[p], x, M + 1, R);
}