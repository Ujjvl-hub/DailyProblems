class Solution {
    int solve(int i, int n, vector<int> &cost,vector<int> &dp){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        int a = cost[i] + solve(i+1,n,cost,dp);
        int b = cost[i] + solve(i+2,n,cost,dp);
        return dp[i] = min(a,b);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(0,n,cost,dp),solve(1,n,cost,dp));
    }
};