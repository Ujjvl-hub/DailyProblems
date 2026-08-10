class Solution {
private:
    bool isCorrect(vector<int> &curr , vector<int> &target){
        for(int i=0;i<256;i++){
            if(curr[i]< target[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> curr(256,0);
        vector<int> target(256,0);

        int n = s.length();
        int low = 0;

        for(int i=0;i<t.length();i++){
            target[t[i]]++;
        }
        int res = INT_MAX;
        int start = 0;

        for(int high = 0;high<n;high++){
            curr[s[high]]++;
            while(isCorrect(curr,target)){
                int len = high - low+1;
                if(len<res){
                    res = len;
                    start = low;
                }
                curr[s[low]]--;
                low++;
            } 
           
        }
        return (res==INT_MAX)?"": s.substr(start,res);
    }
};