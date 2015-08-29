# LongestSubstringWithoutRepeatingChar

## 问题描述

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.


## 问题分析

问题要求我们找出在给定的字符串中最长的不重复子串，很明显，哈希表问题。

最naive的想法就是：

1. 从字符串第一个字符开始遍历，判断当前字符是否已经出现
	1. 如果未出现，记录下字符出现的位置，计数加一，继续遍历
	2. 如果已经出现，则需要判断之前的子字符串是否为当前最长不重复子字符串，是则更新最长不重复子字符串的数值；从该字符已经出现的位置的下一个位置重新计数 
2. 遍历完成，返回最长不重复子字符串的数值

其中需要考虑的细节有：

- 元素是什么？**字符；**哈希表如何表示？**直接使用256甚至128个元素的数组即可模拟哈希表**
- 当遇到重复字符时如何更新计数值和下标？**细节处理方面问题；**接下来是要从之前重复字符下一位开始遍历还是在当前字符处继续遍历？**很明显，相比较之下前者做了无用功；**
- 什么时候更新返回的长度值？**遇到重复字符时；**仅仅这个时候更新吗？如果整个字符串就是没有重复字符怎么办？**所以还是要在遍历结束后再次判断。**

## 解决方案

以下为我的c++代码：

    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0){
            return 0;
        }
        int start = 0;
        int end = 0;
        int max = 0;
        int count = 0;
        int offset = 0;
        vector<int> char2index(256, -1);
        for(int i = 0; i < size; i++){
            if(char2index[s[i]] != -1){
                end = char2index[s[i]];
                for(int j = start; j<=end; j++){
                    char2index[s[j]] = -1;
                }
                if(count > max){
                    max = count;
                }
                offset = end - start + 1;
                count = count - offset;
                start = end + 1;
            }
            char2index[s[i]] = i;
            count ++;
        }
        if(count > max){
            max = count;
        }
        return max;
    }
    
简单说明，start表示最长不重复子字符串的首字母下标，end为尾字母下标，max即为待返回的子字符串长度，count为计数器，offset为每个局部最长不重复子字符串的长度；

遍历字符串，遇到重复字母，更新end，count，max，start，offset；由于并不往回跳转，所以不管是否遇到重复字母，都会更新当前字母的下标以及计数器count；最后再判断count和max，补全不含重复字母的情况。


## 更进一步

从Discuss上面看到一个惊为天人的答案！代码如下：

	int lengthOfLongestSubstring(string s) {
    	// for ASCII char sequence, use this as a hashmap
    	vector<int> charIndex(256, -1);
    	int longest = 0, m = 0;

    	for (int i = 0; i < s.length(); i++) {
        	m = max(charIndex[s[i]] + 1, m);    
        	// automatically takes care of -1 case
        	charIndex[s[i]] = i;
        	longest = max(longest, i - m + 1);
    	}

    	return longest;
	}

不含注释代码总共才10行！不需要重置哈希表内容，通过m来确定最长子字符串的开始处，太巧妙了！这块正是最不熟悉的动态规划内容，容我先去面壁一会儿！