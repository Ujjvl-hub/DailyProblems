class Solution {
private:
    bool solve(int i,int open, string s,vector<vector<int>>& dp){
        if(open<0) return false;
        if(i==s.length()) return open==0;

        if(dp[i][open]!=-1) return dp[i][open];
        if(s[i]=='('){
            return dp[i][open] = solve(i+1,open+1,s,dp);
        }
        else if(s[i]==')'){
            return dp[i][open]  = solve(i+1,open-1,s,dp);
        }
            
        bool take_open = solve(i+1,open+1,s,dp);
        bool take_close = solve(i+1,open-1,s,dp);
        bool skip = solve(i+1,open,s,dp); 
        
        return dp[i][open] = take_open || take_close || skip;
    }
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,dp);
        
    }
};