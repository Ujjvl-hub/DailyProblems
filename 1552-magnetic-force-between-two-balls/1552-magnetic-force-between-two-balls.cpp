class Solution {
private:
    bool isPossible(vector<int> &position, int m, int mid){
        int lastPosition = position[0];
        int ball=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPosition>=mid){
                ball++;
                if(ball==m) return true;
                lastPosition = position[i];
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size()-1;

        sort(position.begin(),position.end());

        int low = 1;
        int high = abs(position[n]-position[0]);

        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(position,m,mid)){
                ans = mid;
                low= mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};