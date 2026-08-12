class Solution {
private:
    bool isPossible(int mid, vector<int> &nums, int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]/mid);
            if(nums[i]%mid!=0) sum+=1;
        }
        if(sum<=threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = 0;
        int ans =-1;
        for(int i=0;i<nums.size();i++){
            high = max(high,nums[i]);
        }

        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(mid,nums,threshold)){
                ans = mid;
               high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};