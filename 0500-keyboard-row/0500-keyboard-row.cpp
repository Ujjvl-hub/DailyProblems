class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> row(26);

        for(char ch : string("qwertyuiop")) {
            row[ch - 'a'] = 0;
        }

        for(char ch : string("asdfghjkl")) {
            row[ch - 'a'] = 1;
        }

        for(char ch : string("zxcvbnm")) {
            row[ch - 'a'] = 2;
        }

        vector<string> ans;

        for(int i = 0; i < words.size(); i++) {

            string word = words[i];

            int target = row[tolower(word[0]) - 'a'];
            bool ok = true;

            for(int j = 0; j < word.length(); j++) {
                char ch = tolower(word[j]);

                if(row[ch - 'a'] != target) {
                    ok = false;
                    break;
                }
            }

            if(ok)
                ans.push_back(word);
        }

        return ans;   
    }
};