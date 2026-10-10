class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int low =0;
        int zero=0;
        
        for(int high = 0;high<nums.size();high++){
            
            if(nums[high]==0){
                zero++;
                while(zero>k){
                    if(nums[low]==0){
                        zero--;
                    }
                    low++;   
                }
               
            }
            maxi = max(maxi,high-low+1);
                
        }
        return maxi;
    }
};