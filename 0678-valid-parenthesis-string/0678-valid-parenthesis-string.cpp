class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        dp[n][0] = true;
        for(int i=n-1;i>=0;i--){ 
            
            for(int j=0;j<n;j++){  // open
                bool isValid = false;
                if(s[i]=='*'){
                    isValid|= dp[i+1][j+1];
                    isValid|=dp[i+1][j];
                    if(j>0){
                        isValid|=dp[i+1][j-1];
                    }

                }else if(s[i]=='('){
                    isValid|=dp[i+1][j+1];
                }else{
                    if(j>0){
                        isValid|=dp[i+1][j-1];
                    }
                }

                dp[i][j] = isValid;
            }
            
        }
        return dp[0][0];
    }
};