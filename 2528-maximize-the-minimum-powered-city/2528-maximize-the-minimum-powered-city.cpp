class Solution {
private:
    bool isValid(long long mid, vector<long long>& diff, int r, int k,int n){
        vector<long long> temp= diff;
        long long cummSum =0;
        for(int i=0;i<n;i++){
            cummSum+=temp[i];

            if(cummSum< mid){
                long long need = mid- cummSum;
                if(need>k) return false;

                k-=need;
                cummSum+=need;
                if(i+2*r+1 < n)
                    temp[i+2*r+1]-=need;

            }
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n,0);

        for(int i=0;i<n;i++){
            diff[max(0,i-r)] +=stations[i];

            if(i+r+1 <n)
                diff[i+r+1]-=stations[i];
        }

        long long low =0;
        long long high = INT_MIN;

        long long sum=0;
        for(int i=0;i<stations.size();i++){
           
            sum+=stations[i];
        }

        high = sum + k;

        long long res = 0;

        while(low<=high){
            long long mid = low+(high-low)/2;
            if(isValid(mid,diff,r,k,n)){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
};