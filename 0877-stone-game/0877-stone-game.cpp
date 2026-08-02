class Solution {
    int solve(int i,int j, vector<int> &piles,vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(i==j) return dp[i][j] =  piles[i];
        int first = piles[i] + min(solve(i+2,j,piles,dp), solve(i+1,j-1,piles,dp));
        int second = piles[j] + min(solve(i,j-1,piles,dp), solve(i+1,j,piles,dp));
        return dp[i][j] = max(first,second);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = 0;
        for(int i=0;i<piles.size();i++){
            total+=piles[i];
        }

        vector<vector<int>> dp(n,vector<int>(n,-1));
        int Alice = solve(0,n-1,piles,dp);
        int Bob = total-Alice;
        return (Alice>Bob)?true:false;
    }
};