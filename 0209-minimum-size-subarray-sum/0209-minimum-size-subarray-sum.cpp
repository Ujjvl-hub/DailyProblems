class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        

        int ans=INT_MAX;
        int sum=0;

        for(int high =0;high<nums.size();high++){
            sum+=nums[high];
            while(sum>=target){
                int len = high-low+1;
                ans = min(ans,len);
                sum-=nums[low];
                low++;
            }
           
        }
    return (ans==INT_MAX)?0:ans;
    }
};