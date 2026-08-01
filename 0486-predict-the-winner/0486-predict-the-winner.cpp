class Solution {

private:

    int solve(int i, int j,vector<int> &nums,vector<vector<int>> &dp){

        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int taken_first = nums[i] + min(solve(i+2,j,nums,dp), solve(i+1,j-1,nums,dp));
        int taken_second = nums[j] + min(solve(i+1,j-1,nums,dp), solve(i,j-2,nums,dp));

        return dp[i][j] = max(taken_first, taken_second);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));
        int total_score=0;
        for(int i=0;i<nums.size();i++){
            total_score+=nums[i];
        }

        int player1 = solve(0,nums.size()-1,nums,dp);

        int player2 = total_score-player1;
        if(player1>= player2) return true;
        else return false;
    }
};