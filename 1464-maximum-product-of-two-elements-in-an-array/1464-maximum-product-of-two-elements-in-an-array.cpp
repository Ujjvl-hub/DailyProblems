class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax = INT_MIN;
        int smax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>fmax){
                smax = fmax;
                fmax = nums[i];
            }
            else if(nums[i]>smax) smax = nums[i];
        }
        return (fmax-1)*(smax-1);
    }
};