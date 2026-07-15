class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        if(n<3) return n;
        int evenSum= n*(n-1);
        int oddSum= n*n;

        int ans=0;
        for(int i=2;i<evenSum;i++){
            if(evenSum%i==0 && oddSum%i==0){
                ans = max(ans,i);
            }
        }
        return ans;
    }
};