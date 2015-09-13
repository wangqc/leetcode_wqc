<h1 id="toc_0">romanToInt</h1>

<h2 id="toc_1"></h2>

<h2 id="toc_2">问题描述</h2>

<p>给出一个罗马数字的字符串，将其转换为整数。罗马数字的范围为1到3999.</p>

<h2 id="toc_3">问题分析</h2>

<p>首先我们需要先知道罗马数字的书写规则。这个可以参考百度百科：</p>

<h4 id="toc_4">记数方法</h4>

<blockquote>
<p>I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000</p>
<p>
1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；<br>
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如：Ⅷ=8；Ⅻ=12；<br>
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ=4；Ⅸ=9；<br>
4、正常使用时，连写的数字重复不得超过三次。</p>
</blockquote>

<h4 id="toc_5">组数规则</h4>

<blockquote>
<p>
1、基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。<br>
2、不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。<br>
3、V 和X 左边的小数字只能用Ⅰ。<br>
4、L 和C 左边的小数字只能用X。<br>
5、D 和M 左边的小数字只能用C。</p>
</blockquote>

<h3 id="toc_6">解题思路</h3>

<ol>
<li>容易想到，需要使用一种方法将I，V，X等字符与相应的数字对应起来，这个使用数组或者字典都可以实现；<br></li>
<li>罗马数字字符串中的字符不是逐个相加，而是根据位置来选择加或者减；根据组数规则2可以知道，我们需要且仅需要保存当前字符的前一个字符即可判定加减；</li>
<li>当前字符与前一字符相同时，仅需加和即可；</li>
<li>当前字符与前一字符不相同时：

<ol>
<li>若当前字符比前一个字符小，需要使用临时变量备份存储当前的加和，再继续加和，并设定一个判断变量表示待判定当前字符是简单加和，还是被之后更大的字符作减法。例子为XXI和XXIX。</li>
<li>若当前字符比前一个字符大，需要查看是否有判断变量，如果是的话，就应该将当前字符减去前一字符，并与备份的加和相加后，更新加和。若不是的话，简单相加即可。</li>
</ol></li>
</ol>

<h2 id="toc_7">解决方案</h2>

<p>以下为我的c++代码：</p>

<pre class="lang:default decode:true " >int romanToInt(string s){
    map&lt;char, int&gt; roman;
    roman[&#39;I&#39;] = 1;
    roman[&#39;V&#39;] = 5;
    roman[&#39;X&#39;] = 10;
    roman[&#39;L&#39;] = 50;
    roman[&#39;C&#39;] = 100;
    roman[&#39;D&#39;] = 500;
    roman[&#39;M&#39;] = 1000;

    const int len = s.size();
    int sum = 0;
    int tmp_sum;
    bool to_judge = false;
    char pre_char = s.at(0);
    for(int i = 0; i &lt; len; i++){
        if(roman[pre_char] &lt; roman[s.at(i)]){
            if(to_judge){
                sum = tmp_sum + roman[s.at(i)] - roman[pre_char];
                to_judge = false;
            }
            else{
                sum = roman[s.at(i)] - sum;
            }
        }
        else if(roman[pre_char] &gt; roman[s.at(i)]){
            tmp_sum = sum;
            sum += roman[s.at(i)];
            to_judge = true;
        }
        else{
            sum += roman[s.at(i)];
        }
        pre_char = s.at(i);
    }
    return sum;

}</pre>

<h2 id="toc_8">更进一步</h2>

<p>如果我们再多想一步，可以想到只要出现IV或者IX，那么我们不管三七二十一，直接对罗马数字字符串所有的字符进行相加，那么结果至少要比正确的大2；同理XC，XL等都是一样道理，这招可以简单理解为<em>欲擒故纵</em>！
以下为leetcode题目discuss的大神的解法：</p>

<pre class="lang:default decode:true " >public int romanToInt(String s) {
    int sum=0;
    if(s.indexOf(&quot;IV&quot;)!=-1){sum-=2;}
    if(s.indexOf(&quot;IX&quot;)!=-1){sum-=2;}
    if(s.indexOf(&quot;XL&quot;)!=-1){sum-=20;}
    if(s.indexOf(&quot;XC&quot;)!=-1){sum-=20;}
    if(s.indexOf(&quot;CD&quot;)!=-1){sum-=200;}
    if(s.indexOf(&quot;CM&quot;)!=-1){sum-=200;}

    char c[]=s.toCharArray();
    int count=0;

    for(;count&lt;=s.length()-1;count++){
       if(c[count]==&#39;M&#39;) sum+=1000;
       if(c[count]==&#39;D&#39;) sum+=500;
       if(c[count]==&#39;C&#39;) sum+=100;
       if(c[count]==&#39;L&#39;) sum+=50;
       if(c[count]==&#39;X&#39;) sum+=10;
       if(c[count]==&#39;V&#39;) sum+=5;
       if(c[count]==&#39;I&#39;) sum+=1;

    }

    return sum;
}</pre>

<p>再更进一步，又有大神指出，以上这种解法虽然简单易懂，但是时间复杂度上不是那么好，而接下来他给出来的解法只需要遍历一次字符串！以下为代码：</p>

<pre class="lang:default decode:true " >public static int romanToInt(String s) {
    int res = 0;
    for (int i = s.length() - 1; i &gt;= 0; i--) {
        char c = s.charAt(i);
        switch (c) {
        case &#39;I&#39;:
            res += (res &gt;= 5 ? -1 : 1);
            break;
        case &#39;V&#39;:
            res += 5;
            break;
        case &#39;X&#39;:
            res += 10 * (res &gt;= 50 ? -1 : 1);
            break;
        case &#39;L&#39;:
            res += 50;
            break;
        case &#39;C&#39;:
            res += 100 * (res &gt;= 500 ? -1 : 1);
            break;
        case &#39;D&#39;:
            res += 500;
            break;
        case &#39;M&#39;:
            res += 1000;
            break;
        }
    }
    return res;
}</pre>

<p>该大神机智地反向遍历，意识到罗马数字都是大数放前面，换言之也就是小数放后面。然后判断后面子串跟5，50，500的大小关系来决定加减。Excellent！</p>

<h2 id="toc_9">题目链接</h2>

<p><a href="https://leetcode.com/problems/roman-to-integer/">romanToInt</a></p>