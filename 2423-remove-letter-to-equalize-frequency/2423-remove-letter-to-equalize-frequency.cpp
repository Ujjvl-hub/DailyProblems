class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(256, 0);
        vector<int> temp(256, 0);

        for (char ch : word) {
            freq[ch]++;
        }
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                temp[freq[i]]++;
            }
        }

        for (int i = 0; i < 256; i++) {

            if (freq[i] == 0) continue;

            freq[i]--;

            int f = 0;

            for (int j = 0; j < 256; j++) {
                if (freq[j] > 0) {
                    f = freq[j];
                    break;
                }
            }

            bool valid = true;
            for (int j = 0; j < 256; j++) {
                if (freq[j] > 0 && freq[j] != f) {
                    valid = false;
                    break;
                }
            }

            freq[i]++;

            if (valid) return true;
        }

        return false;
    }
};