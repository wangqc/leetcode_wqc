# 152-Max Product Subarray

## 要点

- 如果没有0而只有正负数的话，那么就是统计负数个数。若为偶数，则全乘即可；若为奇数，**又有一种情况就是就只有一个负数**，那么肯定就是直接返回该数；若不是则看截掉前面一段还是后面一段（如果一个负数情况这样处理就会返回1错误）
- 如果有0的话，就要按照0来切分了，再分别按照第一步去求每个切分子数组的最大乘积。**需要注意的一点是乘积要跟0作比较看谁大**
