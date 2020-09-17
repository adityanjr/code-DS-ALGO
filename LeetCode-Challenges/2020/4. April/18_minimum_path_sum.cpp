class Solution
{

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        vector<vector<int>> dp(nr, vector<int>(nc));

        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (r == 0 && c == 0)
                {
                    dp[r][c] = grid[0][0];
                }
                else
                {
                    dp[r][c] = grid[r][c] + min(r == 0 ? INT_MAX : dp[r - 1][c], c == 0 ? INT_MAX : dp[r][c - 1]);
                }
            }
        }

        return dp[nr - 1][nc - 1];
    }
};