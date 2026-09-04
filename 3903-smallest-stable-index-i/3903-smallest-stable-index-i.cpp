class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int idx = 0;

        while( idx<nums.size()){
            int mini = INT_MAX;
            int maxi = INT_MIN;

            int highIdx = -1;
            int lowIdx =-1;

            for(int i=0;i<=idx;i++){
                if(nums[i]>maxi){
                    maxi = nums[i];
                    highIdx = i;
                }
            }
            for(int i=idx;i<nums.size();i++){
                if(nums[i]<mini){
                    mini  = nums[i];
                    lowIdx = i;
                }
            }   

            if(maxi - mini<=k){
                return idx;
            }
            idx++;
        }
        
        return -1;


    }
};