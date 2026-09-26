class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = knowledge.size();
        string res = "";
        unordered_map<string,string> mp;
        for(int i=0;i<n;i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    j++;
                }
                string temp = "";
                for(int v = i+1;v<j;v++){
                    temp+=s[v];
                }

                if(mp.find(temp)!=mp.end()){
                    string copy = mp[temp];
                    res+=copy;
                }else {
                    res+="?";
                }
                i = j;

            }else{
                res+=s[i];
            }
        }
        return res;
    }
};