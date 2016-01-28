class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m?matrix[0].size():0;
        vector<int> storeM(m, 0);
        vector<int> storeN(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    storeM[i] = 1;
                    storeN[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(storeM[i]){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(storeN[j]){
                for(int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
