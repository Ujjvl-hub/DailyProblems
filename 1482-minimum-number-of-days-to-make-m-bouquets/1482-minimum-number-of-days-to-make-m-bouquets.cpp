class Solution {
private:
    bool isPossible(int mid, int m, int k, vector<int> &bloomDay){
        int range = 0;
        int count=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                range++;
                if(range==k){
                    count++;
                    if(count==m) return true;
                    range=0;
                }
            }else range = 0;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX;
        int high = INT_MIN;

        for(int i=0;i<bloomDay.size();i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }

        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(isPossible(mid,m,k,bloomDay)){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};