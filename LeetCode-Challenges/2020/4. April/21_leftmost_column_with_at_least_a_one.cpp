class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> d = binaryMatrix.dimensions();
        int r = d[0];
        int c = d[1];

        int row = 0;
        int col = c - 1;

        int ans = -1;

        while (row < r && col >= 0)
        {
            int x = binaryMatrix.get(row, col);
            if (x == 1)
            {
                ans = col;
                col--;
            }
            if (x == 0)
            {
                row++;
            }
        }
        return ans;
    }
};