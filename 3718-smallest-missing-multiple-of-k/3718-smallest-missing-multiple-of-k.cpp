class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = *max_element(nums.begin(), nums.end());
        
        for(int i=k;i<=n;i+=k){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return n + (k - n % k);
    }
};