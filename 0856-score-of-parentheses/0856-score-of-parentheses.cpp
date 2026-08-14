class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(count);
                count=0;
            }else if(s[i]==')' && count!=0){
                count*=2;
                count+=st.top();
                st.pop();
            }else{
                count=1;
                count+=st.top();
                st.pop();
            }
        }
        return count;
    }
};