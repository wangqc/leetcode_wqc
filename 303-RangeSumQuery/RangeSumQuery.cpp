class NumArray {
public:
    vector<int> partSum;
    NumArray(vector<int> &nums) {
        int size = nums.size();
        int tmp;
        for(int i = 0; i < size; i++){
            if(i == 0){
                partSum.push_back(nums[i]);
            }
            else{
                tmp = partSum[i-1] + nums[i];
                partSum.push_back(tmp);
            }
        }
    }

    int sumRange(int i, int j) {
        if(i == 0){
            return partSum[j];
        }
        else{
            return partSum[j] - partSum[i-1];
        }
    }
};
