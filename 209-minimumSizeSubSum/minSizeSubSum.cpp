class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int head = 0, end = 0;
        int tmpsum = 0;
        int minlen = INT_MAX;
        int size = nums.size();
        while(end < size){
            if(tmpsum + nums[end] < s){
                tmpsum += nums[end];
                end++;
                continue;
            }
            else{
                tmpsum += nums[end];
                int len = end - head + 1;
                while(tmpsum - nums[head] >= s){
                    tmpsum -= nums[head];
                    len--;
                    head++;
                }
                tmpsum -= nums[head];
                head++;
                if(len < minlen){
                    minlen = len;
                }
                end++;
            }
        }
        if(minlen == INT_MAX){
            return 0;
        }
        return minlen;
    }
};
