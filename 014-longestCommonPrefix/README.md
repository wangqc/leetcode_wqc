<h1 id="toc_0">LongestCommonPrefix</h1>

<h2 id="toc_1"></h2>

<h2 id="toc_2">问题描述</h2>

<p>给定字符串数组，确定这些字符串的共同前缀子字符串并返回。</p>

<h2 id="toc_3">问题分析</h2>

<p>该题难度不大，基本思想是先直接取一个字符串作为目标字符串，然后将其与剩余的字符串逐个进行比较，在比较的过程中可以不断将目标字符串截短，比较完成后就得到要返回的字符串了。
需要注意的几点：</p>

<ol>
<li>目标字符串的选取，可以使用第一个，也可以选择最短的那个（需要遍历字符串数组）；</li>
<li>在字符串比较时应该注意下标，两字符串长度不一样，选取短的长度为跳出循环条件，否则会有越界问题；</li>
<li>在比较过程中可以先判断空串，从而可以提前返回。</li>
</ol>

<h2 id="toc_4">解决方案</h2>

<p>以下为我的c++代码：</p>

<pre class="lang:default decode:true " >string longestCommonPrefix(vector&lt;string&gt;&amp; strs){
    string newStr;
    int length = strs.size();
    if(length == 0){
        return &quot;&quot;;
    }
    else if(length == 1){
        return strs.at(0);
    }
    else{
        newStr = strs.at(0);
        int sub_len;
        int cur_len;
        for(int i = 1; i &lt; length; i++) {
            sub_len = newStr.size();
            cur_len = strs.at(i).size();
            int j = 0;
            for(; j &lt; sub_len &amp;&amp; j &lt; cur_len; j++){
                if(newStr.at(j) != (strs.at(i)).at(j)){
                    if(j == 0){
                        return &quot;&quot;;
                    }
                    else{
                        newStr = newStr.substr(0, j);
                    }
                    break;
                }
            }
            if(j &lt; sub_len){
                newStr = newStr.substr(0, j);
            }
        }
    }
    return newStr;
}</pre>

<h2 id="toc_5">更进一步</h2>

<p>Discuss中有人提交了一个解决方案（java）如下：</p>

<pre class="lang:default decode:true " >public String longestCommonPrefix(String[] strs) {
    if(strs == null || strs.length == 0)    return &quot;&quot;;
    String pre = strs[0];
    int i = 1;
    while(i &lt; strs.length){
        while(strs[i].indexOf(pre) != 0)
            pre = pre.substring(0,pre.length()-1);
        i++;
    }
    return pre;
}</pre>

<p>该代码很短，也很简明易懂，就是取第一个字符串为目标字符串，遍历剩余字符串是否包含该字符串，是则返回，不是的话就一点点截短字符串。</p>

<p>但是该代码有个地方可以优化，就是空串判断问题，可以避免无谓的截短。</p>

<p>另外在回复中有人提到了时间复杂度的问题，在最坏情况下，该代码的时间复杂度会达到O(n*k^2)，其中n为字符串数组长度，k为字符串的平均长度。该复杂度没有确切去算过，不过比较介意的是indexOf函数。java的indexOf函数为简单匹配函数，复杂度为O(m*n),其中m为待匹配子串长度，n为字符串长度。而在我们的函数中，两字符串确定共同前缀的时间复杂度也就是O(m)。可能是easy难度，所以对时间复杂度的要求不高吧。</p>