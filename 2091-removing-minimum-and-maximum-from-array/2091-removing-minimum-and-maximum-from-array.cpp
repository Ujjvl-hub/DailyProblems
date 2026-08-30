class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIdx = -1;
        int maxIdx = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i;
            }
            
            if(nums[i]<mini){
                mini = nums[i];
                minIdx = i;
            }
        }

        // both deleting from left 
        int leftCost = max(minIdx,maxIdx) +1;

        // both deleting from right
        int rightCost = n-  min(minIdx,maxIdx);

        // min from left max from right
        int c1 = (minIdx+1) + (n-maxIdx);

        // min from right and max from left
        int c2 = (n-minIdx) +  (maxIdx +1);

        return  min(min(leftCost,rightCost), min(c1,c2));
        
    }
};