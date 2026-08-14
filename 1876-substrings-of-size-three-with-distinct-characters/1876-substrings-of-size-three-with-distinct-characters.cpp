class Solution {
private:
    bool check(string s){
        unordered_map<char,int> mp;
        for(int i=0;i<3;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
            }else return false;
        }

        return true;
    }
public:
    int countGoodSubstrings(string s) {
        int count=0;
        for(int low = 0; low + 2 < s.length(); low++) {
            if(check(s.substr(low, 3))) {
                count++;
            }
        }
        return count;
    }
};