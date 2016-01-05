class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()){
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int column = n-1;
        
        while(true){
            while(column >= 0 && matrix[row][column] > target){
                column--;
            }
            if(column < 0){
                return false;
            }
            while(row < m && matrix[row][column] < target){
                row++;
            }
            if(row == m){
                return false;
            }
            if(matrix[row][column] == target){
                return true;
            }
        }
    }
};
