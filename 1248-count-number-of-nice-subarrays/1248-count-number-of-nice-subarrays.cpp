class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        int res = 0;
        int low=0;
        for(int high=0;high<nums.size();high++){
            
            if(nums[high]%2==1) count++;
                
            while(count>k){
                if(nums[low]%2==1) count--;
                low++;
            } 
            if(count==k) {
                int temp = low;
                int cnt = 0;
                while (nums[temp] % 2 == 0) {
                    temp++;
                    cnt++;
                }
                res+=cnt+1;
            }
            
        }
        return res;

    }
};