class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if (size <= 1){
            return 0;
        }
        else{
            int max = min(height[0], height[size-1]) * (size - 1);
            int i = 0, j = size - 1;
            int tmp;
            while(i < j){
                (height[i] < height[j])?(i++):(j--);
                tmp  = min(height[i], height[j]) * (j - i);
                max = ((tmp > max)?tmp:max);
            }
            return max;
        }
    }
};
