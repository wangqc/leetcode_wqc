class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int tmp = x;
        int y = 0;
        while(tmp){
            y = 10*y + tmp%10;
            tmp /= 10;
        }
        if(y == x){
            return true;
        }
        else{
            return false;
        }
    }
};
