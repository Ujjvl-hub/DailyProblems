class Solution {
    vector<int> x ={-1,1,0,0};
    vector<int> y = {0,0,-1,1};

    private:
    bool valid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int n,int m, int i,int j){
        visited[i][j]= true;
        for(int k=0;k<4;k++){
            int row = i+ x[k];
            int col= j + y[k];

            if(valid(row,col,n,m) && grid[row][col]=='1' && !visited[row][col]){
                dfs(grid,visited,n,m,row,col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count=0;

        int i=0;
        int j=0; 

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,visited,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};