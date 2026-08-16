class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int x = abs(nums[i]);
            int target  = x-1;
           if(nums[target]>0){
             nums[target] = -nums[target];
           }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
              res.push_back(i+1);
            }
        }

        return res;
    }
};