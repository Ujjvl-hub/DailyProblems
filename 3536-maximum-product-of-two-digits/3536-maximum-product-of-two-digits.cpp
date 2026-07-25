class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;
        int maxi =0;
        while(n>0){
            num.push_back(n%10);
            n/=10;
        }
        for(int i=0;i<num.size()-1;i++){
            for(int j=i+1;j<num.size();j++){
                int product = num[i]*num[j];
                maxi = max(maxi,product);
            }
        }
        return maxi;
    }
};