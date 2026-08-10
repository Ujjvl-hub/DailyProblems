class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int curr = 0;
        int maxi = 0;
         
        int low = 0;
        int high = minutes-1;

        for(int i=low;i<=high;i++){
            if(grumpy[i]==1){
                curr+=customers[i];
            }
        }

        while(high<n){
            maxi = max(curr,maxi);
            if(grumpy[low]==1){
                curr-=customers[low];
            }

            low++;
            high++;

            if(high==n) break;
            if(grumpy[high]==1){
                curr+=customers[high];
            }
        }
        
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                maxi+=customers[i];
            }
        }
        return maxi;
    }
};