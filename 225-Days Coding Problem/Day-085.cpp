class Solution{
    public:
        int returnXorY(int x, int y, int b) {
            return x * (b&1) + y * (!(b&1));
        }
};
