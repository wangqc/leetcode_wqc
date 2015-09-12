class Solution {
public:
    int myAtoi(string str) {
        long interger = 0;
        bool isNegative = false;
        bool hasSign = false;
        bool skipHead = false;
        string::iterator it;
        for (it = str.begin(); it != str.end(); it++){
            if(*it == '-'){
                if(hasSign){
                    return 0;
                }
                isNegative = true;
                hasSign = true;
                skipHead = true;
            }
            else if(*it == '+'){
                if(hasSign){
                    return 0;
                }
                hasSign = true;
                skipHead = true;
            }
            else if(*it == ' '){
                if(skipHead){
                    break;
                }
            }
            else if(*it < '0' || *it > '9'){
                break;
            }
            else{
                skipHead = true;
                if(isNegative){
                    interger = 10 * interger - (*it - '0');
                    if(interger < INT_MIN){
                        return INT_MIN;
                    }
                }
                else{
                    interger = 10 * interger + (*it - '0');
                    if(interger > INT_MAX){
                        return INT_MAX;
                    }
                }
            }
        }
        return (int)interger;
    }
};
