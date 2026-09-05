class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        int minEle = INT_MAX;

        for(int i=n-1;i>=0;i--){
            if(nums[i]<minEle){
                minEle = nums[i];     
            }
            temp[i] = minEle;
        }

        int maxEle = INT_MIN;

        for(int i=0;i<n;i++){
            maxEle = max(maxEle,nums[i]);
            minEle = temp[i];

            if(maxEle-minEle<=k){
                return i;
            }
        }

        return -1;
    }
};