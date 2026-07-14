class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.length())
            return s;

        //create a 2d vector and initialize it with '\0'
        vector<vector<char>> temp(numRows,vector<char>(s.length(),'\0'));

        // to check the direction
        bool down = true;
        //initial position
        int row =0;
        int col =0;

        // traversal on string
        for(int i=0;i<s.length();i++){
            // insertion
            temp[row][col]= s[i];

            if(down){
                // last row
                if(row == numRows-1){
                    down = false;
                    row--;
                    col++;
                }else{
                    row++;
                }
            }else{
                //first row
                if(row==0){
                    down = true;
                    row++;
                }else{
                    row--;
                    col++;
                }
            }
        }

        string res="";

        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.length();j++){
                if(temp[i][j] != '\0'){
                     res+=temp[i][j];
                }
            }
        }
        return res;
    }
};