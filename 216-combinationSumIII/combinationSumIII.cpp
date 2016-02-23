class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        if(k <= 0 || k > 9 || (1+k)*k/2 > n || (18 - k + 1)*k/2 < n){
            ;
        }
        else{
            vector<int> toinsert;
            combination(ret, toinsert, n, k, 1);
        }
        return ret;
    }
    
    void combination(vector<vector<int>>& ret, vector<int>& toinsert, int target, int num, int start){
        if(!num){
            if(!target){
                ret.push_back(toinsert);
            }
        }
        else{
            for(int i = start; i <= 9; i++){
                if(target >= i){
                    toinsert.push_back(i);
                    combination(ret, toinsert, target - i, num-1, i+1);
                    toinsert.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }
};
