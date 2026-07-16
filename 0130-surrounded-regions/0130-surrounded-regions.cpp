class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(int row,int col, int n, int m ,vector<vector<char>>& board ){
        if(board[row][col]=='O') 
            board[row][col]='T';

        for(int k=0;k<4;k++){
            int r = row + x[k];
            int c = col + y[k];

            if(isValid(r,c,n,m) && board[r][c]=='O'){
                dfs(r,c,n,m,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                        dfs(i, j, n, m, board);
                    }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};