# Longest Palindromic Substring

## 问题描述

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

## 问题分析

问题想要找在给定字符串中最长的回文子串。

问题切入点：**如果有回文子串比当前的已知最长的回文子串更长，那么回文子串的中心点也就更加靠近源字符串的中心点。**

问题转换为如何找到最长回文子串的中心点。而这个又可以划分为多个子问题：

1. 对一个中心点，如何找到关于这个中心点的回文子串？回文子串长度是奇数还是偶数对如何找出回文子串有什么影响？
2. 当一个中心点已经找到回文子串了，接下来的中心点找哪一个？向左还是向右？

通过分析，最后得出的解决思路如下：

先得出源字符串的中心点，以这个中心点找回文子串。回文子串可能是偶数也可能是奇数，从中点可以向左或者向右，这样就是总共四个循环解决问题。

## 解决方案

	class Solution{
	public:
    void judgePalindrome(int left, int right, int str_len, string s, string &LStr, int &max){
        while(left >= 0 && right < str_len && s[left] == s[right]){
            left--;
            right++;
        }
        int len = right - left - 1;
        if(len > max){
            LStr = s.substr(left+1, len);
            max = len;
        }
    }

    string longestPalindrome(string s) {
        int str_len = s.size();
        if(str_len <= 2){
            return s;
        }
        int mid = str_len/2;
        string LStr;
        int left, right;
        int max_len = 0;
        while(mid + 1 < str_len){
            if(s[mid] == s[mid+1]){
                left = mid;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid++;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0){
            if(s[mid] == s[mid-1]){
                left = mid - 1;
                right = mid;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid--;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0 && mid + 1 <str_len){
            if(s[mid-1] == s[mid+1]){
                left = mid-1;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid--;
        }
        
        mid = str_len/2;
        while(mid - 1 >=0 && mid + 1 <str_len){
            if(s[mid-1] == s[mid+1]){
                left = mid-1;
                right = mid+1;
                judgePalindrome(left, right, str_len, s, LStr, max_len);
            }
            mid++;
        }
        return LStr;
    }
    }

## 更进一步

之后再次看代码发现问题切入点看上去没错，但是没有必要。因为你从源字符串的中点开始向左右遍历，即使确实最长回文子串的中心点是源字符串的中点，倘若此时得到的回文子串长度不够大，你还是得继续遍历才能得到最后的结果，所以其实从中心点开始是没有必要的。可以按正常思路从左到右遍历。 
 
另外需要留意的是重复字符，因为多个重复字符的也能够构成回文字符串，但是如果按照判断普通回文字符串的方法去判断的话也是没有太大必要的。


### Solution 1

以下为Discuss中用c++实现的代码：

	string longestPalindrome(string s) {
    	if (s.empty()) return "";
    	if (s.size() == 1) return s;
    	int min_start = 0, max_len = 1;
    	for (int i = 0; i < s.size();) {
      		if (s.size() - i <= max_len / 2) break;
      		int j = i, k = i;
      		while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      		i = k+1;
      		while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      		int new_len = k - j + 1;
      		if (new_len > max_len) { min_start = j; max_len = new_len; }
    	}
    	return s.substr(min_start, max_len);
	}

代码可读性并不高，但是里面的想法很好：

1. 当字符串中剩下的字符个数不及已得到的最长回文子串长度的一半可以提前退出，因为不可能比现有最长回文子串更长的了
2. 当有重复字符时，直接跳过，避免麻烦的比较
3. 中心点从左往右遍历


### Solution 2

以下为Discuss中用python实现的代码：

	class Solution:
    # @return a string
    def longestPalindrome(self, s):
        longest_index = 0
        max_length = 0
        for i in xrange(len(s)):
            if is_palindrome(s, i - max_length, i):
                longest_index = i - max_length
                max_length = max_length + 1
            elif i - max_length - 1 >= 0 and is_palindrome(s, i - max_length - 1, i):
                longest_index = i - max_length - 1
                max_length = max_length + 2

        return s[longest_index:longest_index + max_length]

	def is_palindrome(string, start, end):
    	for i in xrange((end - start + 1) / 2):
        	if string[start + i] != string[end - i]:
            	return False
    	return True

这种实现方法思路很简单，就是从左往右遍历，然后向后判断以当前最长回文子串的长度值大小的子串是否为回文子串，说的有点绕，看代码更加容易懂。

## 题目链接

传送门：[LongestPalindromicSubstring](https://leetcode.com/problems/longest-palindromic-substring/)