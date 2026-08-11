class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};
private:
    bool isValid(int i,int j,int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(mat[i][j]==0) {
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;

            for(int k=0;k<4;k++){
                int r = row + x[k];
                int c = col + y[k];

                if(isValid(r,c,n,m) && res[r][c]==-1){
                    res[r][c] = res[row][col]+1;
                    q.push({r,c});
                }
            }

        }
        return res;
    }
};