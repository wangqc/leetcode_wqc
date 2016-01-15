class Solution {
public:
    bool canJump(vector<int>& nums) {
        int edge = 0;
        int maxStep = nums[0];
        int size = nums.size();
        if(size == 1){
            return true;
        }
        for(int i = 0; i < size; i++){
            if(i > edge){
                edge = maxStep;
                if(edge >= size-1){
                    return true;
                }
            }
            maxStep = max(maxStep, nums[i] + i);
            if(i == maxStep){
                return false;
            }
        }
    }
};
