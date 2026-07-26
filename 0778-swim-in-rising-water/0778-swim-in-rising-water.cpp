class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};
private:

    bool isValid(int i,int j, int n ,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    bool bfs(vector<vector<int>>& grid, int n,int m ,int mid){
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int r = top.first;
            int c = top.second;

            if(r==n-1 && c==m-1) return true;
            for(int k=0;k<4;k++){
                int row = r + x[k];
                int col = c + y[k];

                if(isValid(row,col,n,m) && !visited[row][col] && mid>=grid[row][col]){
                    q.push({row,col});
                    visited[row][col] = true;
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int low= grid[0][0];
        int high = grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                high = max(high,grid[i][j]);
            }
        }

        int res =0;


        while(low<=high){
            int mid = low+ (high-low)/2;
            if(bfs(grid,n,m,mid)){
                res= mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    return res;
        
    }
};