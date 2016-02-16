class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> pathsum(m, vector<int>(n));
        pathsum[0][0] = grid[0][0];
        int layer = 1;
        while(layer < m+n-1){
            for(int i = 0; i <= layer; i++){
                if(i >= m || layer -i >= n){
                    continue;
                }
                int j = layer - i;
                if(i == 0){
                    pathsum[i][j] = pathsum[i][j-1] + grid[i][j];
                }
                else if(j == 0){
                    pathsum[i][j] = pathsum[i-1][j] + grid[i][j];
                }
                else{
                    pathsum[i][j] = grid[i][j] + ((pathsum[i-1][j] > pathsum[i][j-1])?pathsum[i][j-1]:pathsum[i-1][j]);
                }
            }
            layer++;
        }
        return pathsum[m-1][n-1];
    }
};
