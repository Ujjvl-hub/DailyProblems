class Solution {
const int MOD = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = (2 * dp[i - 1]) % MOD;
            char ch = s[i-1];
            if(mp.find(ch)!=mp.end()){
                int j = mp[ch];
                dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
            }
            mp[ch]=i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};