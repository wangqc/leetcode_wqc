class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if(!nums.size()){
            return ret;
        }
        vector<int> subset;
        ret.push_back(subset);
        sort(nums.begin(), nums.end());
        backTrack(ret, nums, subset, 0);
        return ret;
    }
    
    void backTrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>& subset, int start){
        int size = nums.size();
        for(int i = start; i < size; i++){
            subset.push_back(nums[i]);
            ret.push_back(subset);
            backTrack(ret, nums, subset, i+1);
            subset.pop_back();
        }
    }
};
