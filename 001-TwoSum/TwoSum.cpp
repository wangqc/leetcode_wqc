vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoIndex(2,0);
        int size = nums.size();
        if(size <= 1){
            return twoIndex;
        }
        map<int, int> numsMap;
        for(int i = 0; i < size; i++){
            if(numsMap.find(nums[i]) == numsMap.end()){
                numsMap[nums[i]] = i + 1;
            }
            else{
                if(nums[i] * 2 == target){
                    twoIndex[0] = numsMap[nums[i]];
                    twoIndex[1] = i + 1;
                    return twoIndex;
                }
            }
        }
        for(int i = 0; i < size; i++){
            int sub = target - nums[i];
            if(numsMap.find(sub) != numsMap.end() && sub != nums[i]){
                twoIndex[0] = i + 1;
                twoIndex[1] = numsMap[sub];
                return twoIndex;
            }
        }
        return twoIndex;
    }
