class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low =0;
        int high = k-1;

        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double avg = sum/k;

        while(high<nums.size()){
            sum-=nums[low];
            low++;
            high++;
            if(high==nums.size()) break;
            sum+=nums[high];
            avg = max(avg, sum/k);
        }
        return avg;
    }
};