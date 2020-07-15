class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int nr = matrix.size();
        if (nr == 0)
        {
            return 0;
        }
        int nc = matrix[0].size();
        vector<vector<int>> dp(nr + 1, vector<int>(nc + 1));

        int ans = 0;

        for (int r = 1; r < nr + 1; r++)
        {
            int i = r - 1;
            for (int c = 1; c < nc + 1; c++)
            {
                int j = c - 1;
                if (matrix[i][j] == '1')
                {
                    int x = min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]}) + 1;
                    dp[r][c] = x;
                    if (x > ans)
                    {
                        ans = x;
                    }
                }
            }
        }

        return ans * ans;
    }
};