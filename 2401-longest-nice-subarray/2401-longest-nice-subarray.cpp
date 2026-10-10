class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;
        int low =0;
        int mask = 0;

        for(int high = 0;high<nums.size();high++){
            
           
            while((mask & nums[high]) != 0 ){
                if((mask&nums[low])!=0) mask^=nums[low];
                low++;
                
            }
            mask|=nums[high];
            maxi = max(maxi,high-low+1);
        }
        return maxi;
    }
};