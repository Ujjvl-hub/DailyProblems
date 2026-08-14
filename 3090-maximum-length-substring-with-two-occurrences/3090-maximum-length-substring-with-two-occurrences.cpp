class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> temp(26);
        int low =0;
        int maxi =0;
        for(int high = 0;high<s.length();high++){
            temp[s[high]-'a']++;
            while(temp[s[high]-'a'] >2){
                temp[s[low]-'a']--;
                low++;
            }
            maxi = max(maxi,high -low +1);
        }
        return maxi ;
    }
};