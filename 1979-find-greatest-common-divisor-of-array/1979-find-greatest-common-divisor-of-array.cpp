class Solution {
    private:
    int gcd(int a , int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        int ans = gcd(mini,maxi);
        return ans;
    }
};