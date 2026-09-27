class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string res = "";

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(res);
                res = "";
            }else if(s[i]==')'){
                reverse(res.begin(),res.end());
                res = st.top() + res;
                st.pop();
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};