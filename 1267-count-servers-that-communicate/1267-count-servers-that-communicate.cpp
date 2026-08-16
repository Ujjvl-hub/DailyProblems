class Solution {
private:
    bool checkCol(int r,int c,int n,vector<vector<int>> &grid){
        for(int i=0;i<n;i++){
            if(i!=r && grid[i][c]==1){
                return true;
            }
        }
        return false;
    }
    bool checkRow(int r,int c,int m,vector<vector<int>> &grid){
        for(int i=0;i<m;i++){
            if(i!=c && grid[r][i]==1){
                return true;
            }
        }
        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(checkRow(i,j,m,grid) || checkCol(i,j,n,grid)) count++;
                }
            }
        }
        
        return count;
    }
};