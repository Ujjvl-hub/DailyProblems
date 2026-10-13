class Solution {
private:
    static bool cmp(int a, int b){
        return abs(a)<abs(b);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        long long res = 0;
        int i=0;
        int j = nums.size()-1;

        int n = nums.size();

        if(n%2==0){
            while(i<j){
                long long sum = (nums[j]*nums[j]) - (nums[i]*nums[i]);
                res+=sum;
                i++;
                j--;
            }    
        }else{
            while(i<j){
                long long sum = (nums[j]*nums[j]) - (nums[i]*nums[i]);
                res+=sum;
                i++;
                j--;
            } 
            res+=(nums[i]*nums[i]);
        }
        return res;
    }
};