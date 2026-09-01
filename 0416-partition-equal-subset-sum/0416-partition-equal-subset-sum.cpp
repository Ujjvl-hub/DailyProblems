class Solution {
private:
    bool check(int i,int n,int sum, vector<int> &nums,vector<vector<int>> &dp){
        // base case
        if(i==n){
            if(sum==0) return true;
            return false;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool taken = false;
        // include
        if(nums[i]<=sum){
            taken = check(i+1,n,sum-nums[i],nums,dp);
        }
        // exclude
        bool notTaken = check(i+1,n,sum,nums,dp);

        return dp[i][sum] = taken || notTaken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1) return false;
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return check(0,n,sum,nums,dp);
    }
};