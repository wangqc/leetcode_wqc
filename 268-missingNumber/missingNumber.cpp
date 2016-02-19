class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            result ^= nums[i];
            result ^= i;
        }
        result ^= size;
        return result;
    }
};
