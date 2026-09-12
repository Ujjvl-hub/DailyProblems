class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score;
        vector<int> idxs;

        Node() {
            score = 0;
        }
    };
    vector<vector<Node>> dp;
    vector<vector<bool>> visited;

    Node solve(vector<vector<int>>& intervals, int i, int k) {
        // Base case
        if (k == 0 || i >= n)
            return Node();

        // Already calculated
        if (visited[i][k])
            return dp[i][k];

        visited[i][k] = true;

        Node skip = solve(intervals, i + 1, k);

        int wt = intervals[i][2];
        int idx = intervals[i][3];

        int j = nextIdx[i];

        Node temp = solve(intervals, j, k - 1);

        Node take;

        take.score = temp.score + wt;
        take.idxs = temp.idxs;

        take.idxs.push_back(idx);

        // Original indices should be sorted
        sort(take.idxs.begin(), take.idxs.end());

        if (skip.score > take.score) {
            dp[i][k] = skip;
        }
        else if (skip.score < take.score) {
            dp[i][k] = take;
        }
        else {
            // Same score → lexicographically smaller answer
            if (skip.idxs < take.idxs)
                dp[i][k] = skip;
            else
                dp[i][k] = take;
        }

        return dp[i][k];
    }


    int findNext(vector<vector<int>>& intervals, int end) {

        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (intervals[mid][0] > end) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Store original indices
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by start time
        sort(intervals.begin(), intervals.end());

        // Find next non-overlapping interval
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        }


        // DP initialization
        dp.resize(n, vector<Node>(5));
        visited.resize(n, vector<bool>(5, false));


        return solve(intervals, 0, 4).idxs;
    }
};