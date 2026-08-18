class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (auto& [x, count] : freq) {
                if (count == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3
        int ans = -1;

        // Check first element
        int first = nums[0];
        int countFirst = 0;

        for (int x : nums) {
            if (x == first) {
                countFirst++;
            }
        }

        if (countFirst == 1) {
            ans = max(ans, first);
        }

        // Check last element
        int last = nums[n - 1];
        int countLast = 0;

        for (int x : nums) {
            if (x == last) {
                countLast++;
            }
        }

        if (countLast == 1) {
            ans = max(ans, last);
        }

        return ans;
    }
};