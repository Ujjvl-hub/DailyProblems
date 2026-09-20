class Solution {
public:
    int reverseDegree(string s) {
        int res =0;
        for(int i=0;i<s.length();i++){
            int pos = s[i] - 'a'+1;
            int rev = 26 - pos +1;
            res += ((i+1)*rev);
        }
        return res;
    }
};