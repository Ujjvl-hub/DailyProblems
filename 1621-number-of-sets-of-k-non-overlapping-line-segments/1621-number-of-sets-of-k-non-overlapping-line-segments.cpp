
class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][1001] = {};

    int numberOfSets(int n, int k) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }

        for (int j = 1; j <= k; j++) {

            long long suffix = 0;

            for (int i = n - 1; i >= 0; i--) {

                long long take = suffix;

                long long skip = dp[j][i + 1];

                dp[j][i] = (take + skip) % MOD;

                // Update suffix for the next i
                suffix = (suffix + dp[j - 1][i]) % MOD;
            }
        }

        return dp[k][0];
    }
};