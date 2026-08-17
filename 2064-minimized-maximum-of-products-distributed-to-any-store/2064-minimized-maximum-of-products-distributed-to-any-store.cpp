class Solution {
private:
    bool isPossible(int mid, vector<int> &quantities, int n){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            count+=(quantities[i]/mid);
            if(quantities[i]%mid!=0) count++;
            if(count>n){
                return false;
            }
        }  
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high = 0;
        // int ans  =0;
        for(int i=0;i<quantities.size();i++){
            high = max(high,quantities[i]);
        }

        while(low<high){
            int mid= low+(high-low)/2;

            if(isPossible(mid,quantities,n)){
                // ans = mid;
                high = mid;

            }else low = mid+1;
        }
        return low;
    }
};