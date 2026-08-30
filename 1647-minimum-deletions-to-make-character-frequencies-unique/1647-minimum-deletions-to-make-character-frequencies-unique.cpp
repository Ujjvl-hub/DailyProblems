class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(256,0);

        for(char ch: s){
            freq[ch]++;
        }

        int count=0;
        vector<bool> visited(s.length()+1,false);
        for(int i=0;i<256;i++){

            if(freq[i]==0) continue;
            if(!visited[freq[i]]){
                visited[freq[i]] = true;
            }else{
                while(freq[i]> 0 && visited[freq[i]]){
                    freq[i]--;
                    count++;
                }
            }
            visited[freq[i]] = true;
        }

        return count;
    }
};