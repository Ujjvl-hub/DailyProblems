class Solution {
public:
    string addStrings(string num1, string num2) {
        int i= num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        string res="";

        while(i >= 0 && j >= 0){
            int d1 = num1[i] - '0';
            int d2 = num2[j] - '0';

            int sum = d1 + d2 + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;

            i--;
            j--;
        }

        while(i >= 0){
            int sum = (num1[i] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            i--;
        }

        while(j >= 0){
            int sum = (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            j--;
        }

        if(carry)
            res += (carry + '0');


        int start=0;
        int end = res.length()-1;

        while(start<end){
            swap(res[start],res[end]);
            start++;
            end--;
        }
        return res;
    }
};