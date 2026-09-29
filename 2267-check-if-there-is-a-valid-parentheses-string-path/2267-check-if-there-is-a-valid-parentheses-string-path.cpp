
class Solution {
    vector<int> x = {0, 1};
    vector<int> y = {1, 0};

private:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;
        if (grid[0][0] == ')') return false;

        queue<pair<pair<int,int>,int>> p;
        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(
                m, vector<bool>(n + m + 1, false)
            )
        );

        visited[0][0][1] = true;
        p.push({{0, 0}, 1});

        while (!p.empty()) {
            auto a = p.front();
            p.pop();

            int i = a.first.first;
            int j = a.first.second;
            int balance = a.second;

            if (i == n - 1 && j == m - 1) {
                if (balance == 0) return true;
                continue;
            }

            for (int k = 0; k < 2; k++) {
                int r = i + x[k];
                int c = j + y[k];

                if (!isValid(r, c, n, m)) continue;

                int newBalance = balance;

                if (grid[r][c] == '(')
                    newBalance++;
                else
                    newBalance--;

                if (newBalance < 0) continue;

                int rem = (n - 1 - r) + (m - 1 - c);

                if (newBalance > rem) continue;
                if ((newBalance + rem) % 2 != 0) continue;

                if (!visited[r][c][newBalance]) {
                    visited[r][c][newBalance] = true;
                    p.push({{r, c}, newBalance});
                }
            }
        }

        return false;
    }
};