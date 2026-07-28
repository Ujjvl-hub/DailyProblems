class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }

        string left ="";

        string mid ="";

        for(auto it: mp){
            if(it.second%2!=0){
                mid += it.first;
            }

            for(int i=0;i<it.second/2;i++){
                left+=it.first;
            }
        }
        string right = left;
        reverse(right.begin(),right.end());
        return  left + mid + right;

    }
};