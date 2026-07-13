class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;

        for(int i=1;i<=9;i++){
            q.push(i);
        }

        while(!q.empty()){
            int num = q.front();
            q.pop();

            if(num>=low && num<=high){
                res.push_back(num);
            }

            int lastDigit = num%10;

            if(lastDigit<9){
                int nextNum= num*10+(lastDigit+1);
                if (nextNum <= high)
                q.push(nextNum);
            }
            
            
        }
        return res;
    }
};