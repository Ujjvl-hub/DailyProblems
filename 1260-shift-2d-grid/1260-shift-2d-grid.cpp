class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);

        while(k--){
             vector<vector<int>> res(m,vector<int>(n));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j<n-1){
                        res[i][j+1] = grid[i][j];
                    }
                    else if(i<m-1){
                        res[i+1][0] = grid[i][n-1];
                    }
                    else{
                        res[0][0] = grid[m-1][n-1];
                    }
                }
            }
            grid = res;
        }
        return grid;
        
    }
};