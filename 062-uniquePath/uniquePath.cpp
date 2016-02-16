class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0){
            return 0;
        }
        if(m == 1 || n == 1){
            return 1;
        }
        vector<vector<int>> store;
        for(int i = 0; i <= m; i++){
            vector<int> tmp(n+1, 0);
            store.push_back(tmp);
        }
        store[0][1] = 1;
        int layer = 1;
        while(layer <= min(m,n)){
            for(int i = layer; i <= m; i++){
                store[i][layer] = store[i-1][layer] + store[i][layer-1];
            }
            for(int j = layer; j <= n; j++){
                store[layer][j] = store[layer-1][j] + store[layer][j-1];
            }
            layer++;
        }
        return store[m][n];
    }
};
