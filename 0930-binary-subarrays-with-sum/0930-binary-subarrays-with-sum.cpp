class Solution {
private:
    int atMost(vector<int> &nums, int goal){
        if(goal<0) return 0;
        int low=0;
        int count=0;
        int sum=0;
        for(int high = 0; high<nums.size();high++){
            sum+=nums[high];

            while(sum>goal){
                sum-=nums[low];
                low++;
            }
            
            count+=(high-low+1);
            
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};