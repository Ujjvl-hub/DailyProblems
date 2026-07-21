class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(int i,int j,int n, int m , vector<vector<bool>> &visited,vector<vector<int>>& grid){
        visited[i][j] = true;

        for(int k=0;k<4;k++){
            int r = i + x[k];
            int c = j + y[k];
            
            if(isValid(r,c,n,m) && !visited[r][c] && grid[r][c]==0){
                dfs(r,c,n,m,visited,grid);
            } 
            
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0){
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    count++;
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }


        return count;
    }
};