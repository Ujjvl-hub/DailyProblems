class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};

private:
    bool isValid(int i,int j,int n , int m ){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time=0;
        int freshCount=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                }else if(grid[i][j]==1) freshCount++;
            }
        }

        while(!q.empty() && freshCount>0){
            time++;
            int size = q.size();

            while(size--){
                pair<int,int> front = q.front();
                q.pop();

                int r = front.first;
                int c = front.second;

                for(int k=0;k<4;k++){
                    int row = r + x[k];
                    int col = c + y[k];

                    if(isValid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col]=0;
                        freshCount--;
                    }
                }
            }
        }

        if(freshCount>0) return -1;
        return time;
    }
};