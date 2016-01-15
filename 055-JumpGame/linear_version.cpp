class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        for(int maxJump = nums[0]; i < size && i <= maxJump; i++){
            maxJump = max(maxJump, nums[i] + i);
        }
        return i == size;
    }
};
