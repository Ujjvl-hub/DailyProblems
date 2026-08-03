class Solution {

private:
    int solve(int i,int n, vector<int> &stoneValue,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=INT_MAX) return dp[i];

        int sum = 0;
        int best = INT_MIN;

        for(int k=0;k<3 && i+k <n;k++){
            sum+=stoneValue[i+k];

            best = max(best, sum - solve(i + k + 1,n, stoneValue,dp));
        }
        return dp[i] = best;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,INT_MAX);

        int Alice = solve(0,n,stoneValue,dp);
        if (Alice > 0)
            return "Alice";
        else if (Alice < 0)
            return "Bob";
        else
            return "Tie";
    }
};