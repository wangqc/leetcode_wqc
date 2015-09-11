class Solution {
public:
    int reverse(int x) {
        long long new_int = 0LL;
    while(x){
        new_int = new_int * 10 + x % 10;
        x /= 10;
    }
    if(new_int > (1LL << 31) || new_int < (-(1LL << 31)-1)){
        return 0;
    }
    else{
        int another_int;
        another_int = (int)new_int;
        return another_int;
    }
    }
};
