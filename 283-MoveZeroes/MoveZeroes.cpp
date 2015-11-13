class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int cur = 0;
        int index = 0;
        bool startToMove = false;
        for(;cur < size; cur++){
            if(nums[cur] != 0){
                if(!startToMove){
                    continue;
                }
                else{
                    nums[index]  = nums[cur];
                    index++;
                }
            }
            else{
                if(!startToMove){
                    index = cur;
                    startToMove = true;
                }
            }
        }
        if(startToMove){
            for(;index < size; index++){
                nums[index] = 0;
            }
        }
    }
};
