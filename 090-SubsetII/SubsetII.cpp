class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        if(!nums.size()){
            return ret;
        }
        vector<int> subset;
        ret.push_back(subset);
        sort(nums.begin(), nums.end());
        
        int n;
        int start;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]){
                start = n;
            }
            else{
                start = 0;
            }
            n = ret.size();
            for(int j = start; j < n; j++){
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
            
        }
        
        return ret;
    }
};
