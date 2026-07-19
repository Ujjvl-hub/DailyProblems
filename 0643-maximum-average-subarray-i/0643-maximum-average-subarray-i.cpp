class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       

        int low= 0;
        int high = k-1;

        double maxi = INT_MIN;
        double sum = 0;

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        while(high<nums.size()){
            double avg = sum/k;
            maxi = max(avg,maxi);
            low++;
            high++;

            if(high==nums.size()) break;
            else sum = sum- nums[low-1]+ nums[high];
        }
        
        return maxi;
    }
};