class Solution {
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

private:
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(2, INT_MAX)));

        set<tuple<int,int,int,int>> st;

        dist[0][0][0] = 0;
        st.insert({0, 0, 0, 0});

        while (!st.empty()) {
            auto [time, r, c, parity] = *st.begin();
            st.erase(st.begin());

            if (time != dist[r][c][parity]) continue;

            if (r == n - 1 && c == m - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int nr = r + x[k];
                int nc = c + y[k];

                if (!isValid(nr, nc, n, m)) continue;

                int duration = (parity == 0) ? 1 : 2;
                int nextTime = max(time, moveTime[nr][nc]) + duration;
                int nextParity = 1 - parity;

                if (nextTime < dist[nr][nc][nextParity]) {
                    dist[nr][nc][nextParity] = nextTime;
                    st.insert({nextTime, nr, nc, nextParity});
                }
            }
        }

        return -1;
    }
};
