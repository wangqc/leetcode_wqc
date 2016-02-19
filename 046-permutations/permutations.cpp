class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> perm;
        vector<bool> select(nums.size(), false);
        addPermutation(ret, perm, nums, select);
        return ret;
    }
    
    void addPermutation(vector<vector<int>>& ret, vector<int>& perm, vector<int>& nums, vector<bool>& select){
        int size = nums.size();
        if(perm.size() == size){
            ret.push_back(perm);
        }
        for(int start = 0;start < size; start++){
            if(!select[start]){
                perm.push_back(nums[start]);
                select[start] = true;
                addPermutation(ret, perm, nums, select);
                perm.pop_back();
                select[start] = false;
            }
        }
    }
};
