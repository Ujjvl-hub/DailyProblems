class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++){
            //step 1 : window size must be equal to k
            while(!dq.empty() &&  dq.front() <= i-k){
                dq.pop_front();
            }

            // step 2
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            // step 3
            dq.push_back(i);

            // step 4
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};