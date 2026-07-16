class Solution {
    private:
    int getGCD(int n, int m) {
        while (m != 0) {
            int temp = m;
            m = n % m;
            n = temp;
        }
        return n;
    }

public:
    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<long long> temp;
        
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            int n = getGCD(maxi,nums[i]);
            temp.push_back(n);
        }

        sort(temp.begin(),temp.end());
        long long sum=0;
        int start=0;
        int end = temp.size()-1;
        while(start<end){
            sum+=getGCD(temp[start],temp[end]);
            start++;
            end--;
        }
        return sum;
    }
};