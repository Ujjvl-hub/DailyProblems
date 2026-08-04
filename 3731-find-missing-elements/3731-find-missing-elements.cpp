class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> res;

        for(int i=mini+1;i<maxi;i++){
            if(st.find(i)==st.end())res.push_back(i);
        }
        return res;
    }
};