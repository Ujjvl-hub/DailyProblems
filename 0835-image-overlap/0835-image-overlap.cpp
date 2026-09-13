class Solution {
private:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int i, int j){
        int n = img1.size();
        int count =0;
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                int row = r + i;
                int col = c + j;
                if(row<0 || row>=n || col<0 || col>=n) continue;
                if(img1[r][c] == 1 &&  img2[row][col]==1) count++;
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxi = INT_MIN;
        
        for(int i = -n+1;i<n;i++){
            for(int j= -n+1;j<n;j++){
                int count = countOverlap(img1,img2,i,j);
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};