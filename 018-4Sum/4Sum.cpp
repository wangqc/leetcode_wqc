class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> result;
        if(size < 4){
            return result;
        }
        vector<int> element(4,0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                int two_target = target - nums[i] - nums[j];
                int front = j + 1;
                int back = size - 1;
                while(front < back){
                    int sum = nums[front] + nums[back];
                    if(sum > two_target){
                        back--;
                    }
                    else if(sum < two_target){
                        front++;
                    }
                    else{
                        element[0] = nums[i];
                        element[1] = nums[j];
                        element[2] = nums[front];
                        element[3] = nums[back];
                        result.push_back(element);
                        
                        while(front < back && nums[front] == element[2]){
                            front++;
                        }
                        while(front < back && nums[back] == element[3]){
                            back--;
                        }
                    }
                }
                while(j + 1 < size && nums[j+1] == nums[j]){
                    j++;
                }
            }
            while(i + 1 < size && nums[i+1] == nums[i]){
                i++;
            }
        }
        return result;
    }
};
