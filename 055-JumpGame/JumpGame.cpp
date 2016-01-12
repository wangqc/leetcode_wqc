class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> jump_index(size, 0);
        for(int i = 0; i < size; i++){
            jump_index[i] = i + nums[i];
        }
        int last_index = size-1;
        for(int i = size - 2; i >= 0; i--){
            if(jump_index[i] >= last_index){
                last_index = i;
            }
        }
        if(last_index > 0){
            return false;
        }
        else{
            return true;
        }
    }
};
