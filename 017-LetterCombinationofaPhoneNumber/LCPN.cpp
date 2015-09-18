class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0){
            return result;   
        }
        vector<vector<char>> digit_char(10);
        digit_char[2] = {'a', 'b', 'c'};
        digit_char[3] = {'d', 'e', 'f'};
        digit_char[4] = {'g', 'h', 'i'};
        digit_char[5] = {'j', 'k', 'l'};
        digit_char[6] = {'m', 'n', 'o'};
        digit_char[7] = {'p', 'q', 'r', 's'};
        digit_char[8] = {'t', 'u', 'v'};
        digit_char[9] = {'w', 'x', 'y', 'z'};
        int level = 0;
        string insert_str;
        pushLetter(result, digit_char, level, insert_str, digits);
        
        return result;
    }
    
    void pushLetter(vector<string> &result, const vector<vector<char>> &digit_char, int level, string &insert_str, const string &digits){
        if(level == digits.size()){
            result.push_back(insert_str);
        }
        else{
            for(int i = 0; i < digit_char[digits[level]-'0'].size(); i++){
                insert_str.push_back(digit_char[digits[level]-'0'][i]);
                pushLetter(result, digit_char, level+1, insert_str, digits);
                insert_str.pop_back();
            }
        }
    }
};
