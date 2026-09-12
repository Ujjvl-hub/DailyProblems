class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        int count1 = 0;
        int count2 = 0;

        for(int num : nums1) {
            if(st2.find(num) != st2.end()) {
                count1++;
            }
        }

        for(int num : nums2) {
            if(st1.find(num) != st1.end()) {
                count2++;
            }
        }

        return {count1, count2};
    }
};