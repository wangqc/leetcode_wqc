class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        string::iterator it;
        for(it = s.begin(); it != s.end(); it++){
            if((*it) == '(' || (*it) == '[' || (*it) == '{'){
                myStack.push(*it);
            }
            else if((*it) == ')'){
                if(myStack.empty()){
                    return false;
                }
                else if(myStack.top() != '('){
                    return false;
                }
                myStack.pop();
            }
            else if((*it) == ']'){
                if(myStack.empty()){
                    return false;
                }
                else if(myStack.top() != '['){
                    return false;
                }
                myStack.pop();
            }
            else{
                if(myStack.empty()){
                    return false;
                }
                else if(myStack.top() != '{'){
                    return false;
                }
                myStack.pop();
            }
        }
        if(myStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
