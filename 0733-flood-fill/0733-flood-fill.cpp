class Solution {
    vector<int> x = {-1,1,0,0};
    vector<int> y = {0,0,-1,1};
    private:
    bool isValid(int i,int j, int n ,int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }


    void dfs(int r, int c,int n,int m, vector<vector<bool>> &visited,vector<vector<int>>& image,int color, int initialColor){
        visited[r][c]= true;
        image[r][c] = color;

        for(int k=0;k<4;k++){
            int row = r + x[k];
            int col = c + y[k];

            if(isValid(row,col,n,m) && !visited[row][col] && image[row][col]==initialColor){
                dfs(row,col,n,m,visited,image,color,initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int initialColor = image[sr][sc];
        dfs(sr,sc,n,m,visited,image,color,initialColor);
        return image;
    }
};