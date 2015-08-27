# Two Sum

## 问题描述

给定一个整型数组以及一个目标整数，在数组中找到两个数，符合相加的和等于目标整数。以数组形式返回这两个数在数组中的下标。可以假定只有一个答案。

## 问题分析

本题是一道关于哈希表的非常经典的算法题。

基本思路是遍历数组的每个元素，将数组元素和目标整数作差，然后查找该整数是否在数组中，是的话可以则返回两者的下标。

具体步骤为：

- 遍历数组，如果数组元素没有在哈希表中出现，存储；如果出现过，判断该元素的两倍是否为目标整数，是的话返回两者下标；如果不是则继续遍历，不存储当前数组元素；
- 再次遍历数组，将当前元素和目标整数作差，再查找哈希表中是否存在差对应的值。存在则返回两者下标；需要注意一点的是要判断差是否跟元素本身的值相同。

## 解决方案

以下为我的c++代码：

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

## 更进一步

提交代码之后发现我的解决方案的效率比95%的提交要差。从Discuss可以看到投票最多的代码如下：

	vector<int> twoSum(vector<int> &numbers, int target)
	{
    	unordered_map<int, int> hash;
    	vector<int> result;
    	for (int i = 0; i < numbers.size(); i++) {
    		int numberToFind = target - numbers[i];
    		
    		if (hash.find(numberToFind) != hash.end()) {
    			result.push_back(hash[numberToFind] + 1);
    			result.push_back(i + 1);            
    			return result;
        	}

        	hash[numbers[i]] = i;
    	}
    	return result;
	}

从上面的代码可以看到我有以下几点不足：

1. 首先我使用的数据结构是map，map是使用红黑树存储，查询速度为o(nlogn)；而大牛代码使用的是unordered\_map是哈希表存储，查询速度为o(n)；由于本题不需要对存储的元素进行排序，只需要判定是否存在即可，所以使用unordered\_map即可；
2. 大牛代码只通过一次遍历；而我是使用了两次遍历；
3. 为什么要两次遍历呢？因为我一开始想法就是把数组中的元素下标全部存储下来，再进行判断；这样做的坏处一个是多了一次遍历，另一个就是将问题复杂化了，需要特别考虑相同元素相加刚好等于目标整数的情况。像大牛代码里面就是一种“雁过不留痕”的做法，立刻判定，有就可以直接返回，一次遍历，全部解决。

## 题目链接

[Two Sum](https://leetcode.com/problems/two-sum/)