class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount=0;
        int maxi =-1;

        int low =0;
        for(int high = 0;high<nums.size();high++){
            if(nums[high]==0) zeroCount++;
            
            // shrinking
            while(zeroCount>1){
                if(nums[low]==0) zeroCount--;
                low++;
            }
            maxi = max(maxi,high-low);
        }
        return maxi;
    }
};