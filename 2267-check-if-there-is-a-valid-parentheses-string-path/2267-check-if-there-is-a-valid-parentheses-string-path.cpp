
class Solution {
    vector<int> x = {0, 1};
    vector<int> y = {1, 0};

private:
    bool dfs(int i, int j, int balance,
             vector<vector<char>>& grid,
             vector<vector<vector<int8_t>>>& dp) {
        
        int n = grid.size();
        int m = grid[0].size();

        if (grid[i][j] == '(') balance++;
        else balance--;

        if (balance < 0) return false;

        int rem = (n - 1 - i) + (m - 1 - j);

        if (balance > rem) return false;
        if ((balance + rem) % 2 != 0) return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        int &ans = reinterpret_cast<int&>(dp[i][j][balance]);
        // Use the memoization array below instead.
        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;
        if (grid[0][0] == ')') return false;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                m, vector<int>(n + m + 1, -1)
            )
        );

        return solve(0, 0, 0, grid, dp);
    }

private:
    bool solve(int i, int j, int balance,
               vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[i][j] == '(') balance++;
        else balance--;

        if (balance < 0) return false;

        int rem = (n - 1 - i) + (m - 1 - j);

        if (balance > rem) return false;
        if ((balance + rem) % 2 != 0) return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        if (i + 1 < n)
            ans = solve(i + 1, j, balance, grid, dp);

        if (!ans && j + 1 < m)
            ans = solve(i, j + 1, balance, grid, dp);

        return dp[i][j][balance] = ans;
    }
};