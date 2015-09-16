class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int min = INT_MAX;
        bool isNeg;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            int new_target = target - nums[i];
            int front = i + 1;
            int back = size - 1;
            while(front < back){
                int sum = nums[front] + nums[back];
                if(sum > new_target){
                    if((sum - new_target) < min){
                        min = sum - new_target;
                        isNeg = false;
                    }
                    back--;
                }
                else if(sum < new_target){
                    if((new_target - sum) < min){
                        min = new_target - sum;
                        isNeg = true;
                    }
                    front++;
                }
                else{
                    return target;
                }
            }
        }
        return target+(isNeg?(-min):min);
    }
};
