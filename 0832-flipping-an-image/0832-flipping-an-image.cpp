class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();

        // vector<vector<int> res(m,vector<int>(n));
        for(int i=0;i<n;i++){
            int left = 0;
            int right = image[i].size()-1;
            
            while(left<right){
                swap(image[i][left],image[i][right]);
                left++;
                right--;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                image[i][j] = 1-image[i][j];
            }
        }
        return image;
    }
};