class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int low = 0;
        int high = 0;
        int maxi = 0;

        while(high<nums.size()){
            freq[nums[high]]++;
            high++;

           while(freq[nums[high-1]]> k){
            freq[nums[low]]--;
            low++;
           }
           maxi = max(maxi,high-low);
           
        }
        return maxi;
    }
};