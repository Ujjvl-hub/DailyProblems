class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> temp;

        // {value, original index}
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        int grp = 0;

        // original index -> group
        vector<int> indexToGrp(n);

        // group -> sorted values
        unordered_map<int, list<int>> grpToList;

        indexToGrp[temp[0].second] = grp;
        grpToList[grp].push_back(temp[0].first);

        for (int i = 1; i < n; i++) {

            if (temp[i].first - temp[i - 1].first > limit) {
                grp++;
            }

            indexToGrp[temp[i].second] = grp;
            grpToList[grp].push_back(temp[i].first);
        }

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int group = indexToGrp[i];

            res[i] = grpToList[group].front();
            grpToList[group].pop_front();
        }

        return res;
    }
};