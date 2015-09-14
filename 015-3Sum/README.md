# 3Sum

## 问题分析

由于之前已经做过了2Sum，按照naive的想法就是在数组中固定一个数，将剩下的数组调用2Sum可求，代码如下：

	class Solution {
	public:
   		vector<vector<int>> threeSum(vector<int>& nums) {
        	int size = nums.size();
        	unordered_map<int, int> tripletMap;
        	vector<vector<int>> result;
        	vector<int> element(3, 0);
        	if(size < 3){
            	return result;
        	}
        	sort(nums.begin(), nums.end());
        	for(int i = 0; i < size - 2; i++){
            	if(i > 0 && nums[i] == nums[i-1]){
                	continue;
            	}
            	int target = -nums[i];
            	for(int j = i+1; j <=size - 1; j++){
                	int numToFind = target - nums[j];
                	if(tripletMap.find(numToFind) != tripletMap.end()){
                    	element[0] = -target;
                    	element[1] = numToFind;
                    	element[2] = nums[j];
                    	result.push_back(element);
                	}
                	tripletMap[nums[j]] = j;
            	}
            	tripletMap.clear();
        	}
        	return result;
    	}
	};

后来提交之后发现时间复杂度太大，没办法，只能放弃这种解法。

最后查看Discuss的解法，发现排序是需要的，因为题干中要求元组中数值是排序状态；先取定一个数也是必要的，只是剩下数组的处理就不大一样了。既然已经是排好序的了，就可以采用双指针从剩余数组的两头往中间遍历了。特别需要注意的是需要判重。