class Solution {
public:
    string countAndSay(int n) {
        
        string res="1";
        
        for(int i=0;i<n-1;i++){
            string next = "";
            int count=1;
            for(int j=1;j<res.length();j++){
                if(res[j]==res[j-1]) count++;
                else if(res[j]!=res[j-1]) {
                    next+=(count+'0');
                    next+=(res[j-1]);
                    count=1;
                }
            }
            next+=(count+'0');
            next+=res.back();
           res=next;
        }

        return res;

    }
};