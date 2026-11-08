class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right = height.size()-1;
        int maxi = INT_MIN;
        while(left<right){
            int length = min(height[left],height[right]);
            int width = right-left;
            int ans = length*width;
            maxi = max(ans,maxi);
            if(height[left]<height[right])left++;
            else if(height[left]>height[right]) right--;
            else left++;

        }
        return maxi;
    }
};