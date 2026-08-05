class Solution {
private:
    bool isPossible(int mid, vector<int>& weights, int days){
        int dayCount= 1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }else{
                dayCount++;
                if(dayCount>days) return false;
                sum= weights[i];
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;

        for(int i=0;i<weights.size();i++){
            low = max(low,weights[i]);
            high+=weights[i];
        }

        while(low<high){
            int mid = low+(high-low)/2;
            if(isPossible(mid,weights,days)){
                high = mid;
            }else low = mid+1;
        }
        return low;
    }
};