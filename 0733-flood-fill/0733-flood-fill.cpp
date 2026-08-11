class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};
private:
    bool isValid(int i,int j, int n ,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(int i,int j, int color,vector<vector<int>>& image,vector<vector<bool>>& visited,int n,int m, int originalCol){
        visited[i][j] = true;
        image[i][j] = color;
        

        for(int k=0;k<4;k++){
            int r = i + x[k];
            int c = j +y[k];

            if(isValid(r,c,n,m) && !visited[r][c] && image[r][c]==originalCol){
                dfs(r,c,color,image,visited,n,m,originalCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int originalCol = image[sr][sc];

        dfs(sr,sc,color,image,visited, n,m,originalCol);
        return image;
    }
};