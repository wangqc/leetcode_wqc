class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(!matrix.size()){
            return ret;
        }
        int m = matrix.size(), n = matrix[0].size();
        int leftMost = 0, rightMost = n-1;
        int upMost = 0, downMost = m-1;
        int i = 0, j;
        int count = 0;
        while(rightMost - leftMost >= 0 && downMost - upMost >= 0){
            switch(count%4){
                case 0:
                    for(j = leftMost; j <= rightMost; j++){
                        ret.push_back(matrix[i][j]);
                    }
                    upMost++;
                    j--;
                    break;
                case 1:
                    for(i = upMost; i <= downMost; i++){
                        ret.push_back(matrix[i][j]);
                    }
                    rightMost--;
                    i--;
                    break;
                case 2:
                    for(j = rightMost; j >= leftMost; j--){
                        ret.push_back(matrix[i][j]);
                    }
                    downMost--;
                    j++;
                    break;
                case 3:
                    for(i = downMost; i >= upMost; i--){
                        ret.push_back(matrix[i][j]);
                    }
                    leftMost++;
                    i++;
                    break;
                default:
                    break;
            }
            count++;
        }
        return ret;
    }
};
