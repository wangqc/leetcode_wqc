class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        vector<int> element(3, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            int target = -nums[i];
            int begin = i+1;
            int end = size - 1;
            while(begin < end){
                if(nums[begin] + nums[end] < target){
                    begin++;
                }
                else if(nums[begin] + nums[end] > target){
                    end--;
                }
                else{
                    element[0] = nums[i];
                    element[1] = nums[begin];
                    element[2] = nums[end];
                    result.push_back(element);
                    while(begin < end && nums[begin] == element[1]){
                        begin++;
                    }
                    while(begin < end && nums[end] == element[2]){
                        end--;
                    }
                }
            }
            while(i+1 < size && nums[i+1] == nums[i]){
                i++;
            }
        }
        return result;
    }
};
