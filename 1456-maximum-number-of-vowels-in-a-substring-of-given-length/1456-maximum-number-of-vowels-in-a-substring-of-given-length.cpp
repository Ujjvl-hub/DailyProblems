class Solution {
    private:
    bool isVowel(char ch){
        if(ch=='a' || ch== 'e'|| ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int maxi = INT_MIN;
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }

        int low = 0;
        int high = k-1;

        while(high<s.length()){
            maxi = max(maxi,count);
            low++;
            high++;

            if(!isVowel(s[low-1]) && isVowel(s[high])) count++;
            else if(isVowel(s[low-1]) && !isVowel(s[high])) count--;
        }
        return maxi;
    }
};