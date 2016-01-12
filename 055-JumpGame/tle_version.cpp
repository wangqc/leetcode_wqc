class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return true;
        }
        return backTrack(nums,0);
    }
    
    bool backTrack(vector<int>& nums, int start){
        if(start >= nums.size()-1){
            return true;
        }
        else if(nums[start] == 0){
            return false;
        }
        for(int i = nums[start]; i > 0; i--){
            if(backTrack(nums, start+i)){
                return true;
            }
        }
        return false;
    }
};
