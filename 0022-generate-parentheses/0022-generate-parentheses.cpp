class Solution {
private:
    void solve(string &curr,int n, vector<string> &res,int open, int close){
        
        if(open==n && close==n){
            res.push_back(curr);
            return ;
        }

        if(open<n){
            char ch = '(';
            curr+=ch;
            solve(curr,n,res,open+1,close);
            curr.pop_back();
        }
        if(close<open){
            char ch = ')';
            curr+=ch;
            solve(curr,n,res,open,close+1);
            curr.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        solve(curr,n,res,0,0);
        return res;
    }
};