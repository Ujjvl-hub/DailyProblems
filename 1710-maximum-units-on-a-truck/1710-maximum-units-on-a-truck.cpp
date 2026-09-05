class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b){
        return b[1]<a[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int i=0;
        int ans = 0;
        while(truckSize > 0 && i<n){
            int t = min(boxTypes[i][0],truckSize);
            truckSize-=t;
            ans+=t*boxTypes[i][1];
            i++;
        }
        return ans;
    }
};