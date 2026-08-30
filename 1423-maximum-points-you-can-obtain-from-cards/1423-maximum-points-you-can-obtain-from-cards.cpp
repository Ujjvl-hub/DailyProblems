class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for(int i=0;i<n;i++){
            total+=cardPoints[i];
        }

        int maxi = INT_MIN;
        int curr = 0;
        for(int i=0;i<n-k;i++){
            curr+=cardPoints[i];
        }

        maxi = max(maxi,total-curr);

        int low =0;
        int high = n-k-1;
        while(high<n-1){
            curr-= cardPoints[low];
            low++;
            high++;
            if(high==n) break;
            curr+=cardPoints[high];
            maxi = max(maxi,total-curr);
        }
        return maxi;
    }
};