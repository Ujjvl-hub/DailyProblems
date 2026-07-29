class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(nums[0]< nums[n-1]) return nums[0];
        else{
            int res =-1;
            int low= 0;
            int high = n-1;
            while(low<=high){
                int mid = low+(high-low)/2;

                if(nums[mid] > nums[n-1]){
                    low = mid+1;
                }else{
                    res = mid;
                    high = mid-1;
                }
            }
            return nums[res];
        }
        return -1;
    }
};