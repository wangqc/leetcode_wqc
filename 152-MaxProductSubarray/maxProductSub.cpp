class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int start, end;
        int hasStart = false;
        int maxP = nums[0];
        int subMax;
        int hasZero = false;
        for(int i = 0; i <size; i++){
            if(nums[i] != 0 && !hasStart){
                start = i;
                hasStart = true;
            }
            if(nums[i] == 0 && hasStart){
                hasZero = true;
                end = i;
                subMax = subMaxProduct(nums,start,end);
                if(subMax > maxP){
                    maxP = subMax;
                }
                hasStart = false;
            }
        }
        if(hasStart){
            subMax = subMaxProduct(nums, start, size);
            if(subMax > maxP){
                maxP = subMax;
            }
        }
        if(hasZero){
            return max(maxP, 0);
        }
        else{
            return maxP;
        }
    }
    
    int subMaxProduct(vector<int>& nums, int start, int end){
        int product = 1;
        int countNeg = 0;
        int beforeNeg = 1;
        int afterNeg = 1;
        int firstNeg = 0;
        int lastNeg = 0;
        bool first = true;
        for(int i = start; i<end; i++){
            product *= nums[i];
            if(nums[i]<0){
                countNeg++;
                if(first){
                    firstNeg = i;
                    first = false;
                }
                lastNeg = i;
            }
        }
        if(countNeg&1){
            if(start == end-1){
                return product;
            }
            for(int i = start; i <= firstNeg; i++){
                beforeNeg *= nums[i];
            }
            for(int i = end-1; i >= lastNeg; i--){
                afterNeg *= nums[i];
            }
            if(beforeNeg > afterNeg){
                return product/beforeNeg;
            }
            else{
                return product/afterNeg;
            }
        }
        else{
            return product;
        }
    }
};
