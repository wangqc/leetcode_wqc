class Solution {
public:
    int addDigits(int num) {
        int sum = 100;
        while(sum/10){
            sum = 0;
            while(num>0){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }
};
