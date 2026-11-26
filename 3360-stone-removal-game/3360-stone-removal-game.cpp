class Solution {
private:
    bool possible(int n){
        int remove = 10;
        bool aliceTurn = true;
        if(n<remove) return false;
        while(n>=remove){
            n-=remove;
            remove--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        if(!possible(n)){
            return false;
        }
        return true;
    }
};