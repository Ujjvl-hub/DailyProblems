class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> idx;

        for (int i = 0; i < nums.size(); i++) {
            idx.push_back({nums[i], i}); 
        }

        sort(idx.begin(),idx.end());

        int i=0;
        int j= nums.size()-1;

        vector<int> res;

        while(i<j){
            if(idx[i][0]+idx[j][0]==target){
                res.push_back(idx[i][1]);
                res.push_back(idx[j][1]);
            }

            if(target> idx[i][0]+idx[j][0]) i++;
            else j--;

        }
        return res;
        
    }
};