class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        if(!nums.size()){
            return ret;
        }
        ret.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int n;
        while(i < nums.size()){
            int count = 1;
            
            while(count + i < nums.size() && nums[count+i] == nums[i])
                count++;
            
            n = ret.size();
            for(int j = 0; j < n; j++){
                vector<int> subset = ret[j];
                for(int k = 0; k < count; k++){
                    subset.push_back(nums[i]);
                    ret.push_back(subset);
                }
            }
            i += count;
        }
        return ret;
    }
};
