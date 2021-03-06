# Palindrome Number

## 问题描述

判断一个整数是否为回文数，不要使用额外空间

## 问题分析

需要理清一个概念，“额外空间”指的是数组或者字符串之类的，也就是还是可以使用整型变量的。

至此，问题就很容易解决了。将传入的数倒转过来存到一个新的数，再比较是否相等即可。需要注意负数都不是回文数。

## 更进一步

在Discuss中有一个比较好的解决方法，有几点值得借鉴：

1. 如果数最后一位为0而数不是0，那么肯定不是回文数
2. 可以不用完全倒转过来，倒转一半之后比较原数是否与倒转的数相等或者是倒转的数的十分之一即可

