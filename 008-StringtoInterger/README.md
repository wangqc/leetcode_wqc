# String to Interger

## 问题描述

实现atoi（String to Interger）

## 解题思路

本题关键就是各种情况的考虑：

1. 最简单的是全部为数字，直接转换
2. 正负符号：当有‘＋’符号时，skip；当有‘－’符号时，需要清楚是负数；当多于一个正负符号时，直接返回0；
3. 当字符串前面有空格符时，skip；当已经出现数字或者正负符号后再出现空格符，则返回已经转换的数字；
4. 当出现除数字，正负符号，空格符的其他符号时，返回已经出现的数字

之后就是对这几种情况进行考虑即可。