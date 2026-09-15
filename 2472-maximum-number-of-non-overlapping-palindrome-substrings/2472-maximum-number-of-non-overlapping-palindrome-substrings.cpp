class Solution {
private:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s, int k,int i,int j,vector<vector<int>> &dp){
        if(i>=s.length() || j>=s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalindrome(i,j,s)){
            int take = 1 + solve(s,k,j+1,j+k,dp);
            int grow = solve(s,k,i,j+1,dp);
            int slide = solve(s,k,i+1,j+1,dp);
            return dp[i][j] = max({take,grow,slide});
        }

        int grow = solve(s,k,i,j+1,dp);
        int slide = solve(s,k,i+1,j+1,dp);

        return dp[i][j] = max(grow,slide);
    }
public:
    int maxPalindromes(string s, int k) {
        if(k==1) return s.length();
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,-1));
        return solve(s,k,0,k-1,dp);
    }
};