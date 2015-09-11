class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        int size = s.size();
        if(size <= 1){
            return s;
        }
        vector<vector<char>> zigzag(numRows);
        string newStr;
        int rows = 0;
        int columns = 0;
        for(int i = 0; i < size; i++){
            if(columns % 2 == 0){
                zigzag[rows].push_back(s[i]);
                rows++;
                if(rows == numRows){
                    rows = rows - 2;
                    if(numRows != 2){
                        columns++;
                    }
                }
            }
            else{
                zigzag[rows].push_back(s[i]);
                if(rows == 1){
                    columns++;
                }
                rows--; 
            }
        }
        vector<char>::iterator it;
        for(int i = 0; i < numRows; i++){
            for(it = zigzag[i].begin(); it != zigzag[i].end(); it++){
                newStr.push_back(*it);
            } 
        }
        return newStr;
    }
};
