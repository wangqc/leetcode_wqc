class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(!size){
            return ret;
        }
        int maj1 = 0, maj2 = 1, count1 = 0, count2 = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == maj1){
                count1++;
            }
            else if(nums[i] == maj2){
                count2++;
            }
            else if(!count1){
                maj1 = nums[i];
                count1++;
            }
            else if(!count2){
                maj2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == maj1){
                count1++;
            }
            if(nums[i] == maj2){
                count2++;
            }
        }
        if(count1 > size/3){
            ret.push_back(maj1);
        }
        if(count2 > size/3){
            ret.push_back(maj2);
        }
        return ret;
    }
};
