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
        
        vector<string> tmp;
        result.push_back("");
        for(int i = 0; i < digits.size(); i++){
            for(int j = 0; j < digit_char[digits[i] - '0'].size(); j++){
                int size = result.size();
                for(int k = 0; k < size; k++){
                    tmp.push_back(result[k] + digit_char[digits[i] - '0'][j]);
                }
            }
            result = tmp;
            tmp.clear();
        }
        
        return result;
    }
};
