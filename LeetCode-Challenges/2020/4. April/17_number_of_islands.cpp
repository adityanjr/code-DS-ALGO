class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int nr = grid.size();
        int nc = grid[0].size();

        int n = 0;

        // check bounds
        auto inside = [&](int row, int col) {
            return row >= 0 && row < nr && col < nc && col >= 0;
        };

        // all_directions
        vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // visited matrix
        vector<vector<bool>> visited(nr, vector<bool>(nc));

        // BFS
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (!visited[r][c] && grid[r][c] == '1')
                {
                    n++;
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    visited[r][c] = true;
                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (pair<int, int> dir : dirs)
                        {
                            int newr = p.first + dir.first;
                            int newc = p.second + dir.second;

                            if (inside(newr, newc) && !visited[newr][newc] && grid[newr][newc] == '1')
                            {
                                visited[newr][newc] = true;
                                q.push({newr, newc});
                            }
                        }
                    }
                }
            }
        }

        return n;
    }
};