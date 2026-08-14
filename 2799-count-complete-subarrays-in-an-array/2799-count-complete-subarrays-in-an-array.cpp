class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int distinct  = st.size();

        int low=0;
        int high=0;

        unordered_map<int,int> mp;
        int count=0;

        while(high<nums.size()){
            mp[nums[high]]++;

            while(mp.size()==distinct){
                count+=(nums.size()-high);

                mp[nums[low]]--;
                if(mp[nums[low]]==0){
                    mp.erase(nums[low]);
                }
                low++;
            }
            high++;

        }
        return count;
    }
};