/* 
来源：算法经典面试题
类属：数据结构
序号：1-字符串
*/

#include<iostream>
#include<string>
#include<map>
#include<string.h>       //  memset

using namespace std;

class solution{
public:
    /*
    题目：
        给定一个字符串，找出不含有重复字符的【最长子串】的长度。
        如：'bbbbb' 的最长子串长度=1。
            'pwwkew'的最长子串长度=3。
    思路：
        因为求的是长度，且字串不重复，因此可以考虑 记录起始位置点，往后遍历过程中，
        起始位置到当前位置中，没有重复的字符时，更新计算当前子串的长度；
                            有重复的字符时，更新起始位置点。
        这样，就存在两个问题：
        1-怎么更新起始位置点时？ 要求当前重复字符的上一个位置处为起始位置点。【因为 a--b的长度=b-a+1】
        2-如何快速遍历当前位置的字符在以往走过的路程中存在与否？ 选择map红黑树，这样【遍历速度够快】。
            具体怎么使用红黑树？ 
            因为要看重复的字符，而key不能有重复值，因此，key存放以往遍历过程中的字符；value存放对应的位置。
            这样，通过find函数遇到重复的字符时，就可以随时更改其对应位置的value值。
        所以，整体的解题逻辑就是：
        map  不重复字符key 和 对应的最后边位置value
        遍历字符串过程中 用map来快速遍历 当前字符是否重复，以及，及时更新字符重复后的起始子串计数位置，
        同时，和记录的最大子串长度比较更新。
        最终，遍历完成，得到记录的最长不重复子串长度。
    */
    int lengthOfLongestSubstring1(string s){
        map<char, int> m;  // 存放 不重复的字符key 和 对应的最后边位置value
        int maxLen = 0; 
        int lastRepeatPos = -1;  // 当前的 不含重复字符的最长子串 的起始位置-1。
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end() && lastRepeatPos<m[s[i]]){     
                // m中找到字母s[i]即s[i]发生重复时 且 该重复字母的位置 超过了 原有子串的起始字符位置 时，
                // 替换 子串的起始字符位置 为 该重复字母的前一个重复处位置（相对于当前位置的前一个）。
                // 重复的字母s[i]后续更新其位置。
                // 且后面的小于逻辑 是为了保证  存在多个重复字符时，及时更新起始位置点。
                lastRepeatPos = m[s[i]];
            }
            if(i-lastRepeatPos > maxLen){
                maxLen = i - lastRepeatPos;   // 当前位置 减去 （不重复字符位置-1） 即==最大子串长度
            }
            m[s[i]] = i;
        }
        return maxLen;
    }

    // not use map
    int lengthOfLongSubstring(string s){
        const int MAXCHARS = 256;
        int m[MAXCHARS];
        memset(m, -1, sizeof(m));
        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if(m[s[i]]!=-1 && lastRepeatPos < m[s[i]]){
                lastRepeatPos = m[s[i]];
            }
            if(i-lastRepeatPos > maxLen){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};

int main(){
    solution solve;
    string s;
    while(cin >> s){
        solve.lengthOfLongSubstring(s) 
        solve.lengthOfLongestSubstring1(s)
        cout << s << " : " << solve.lengthOfLongSubstring(s) << endl;
        cout << s << " : " << solve.lengthOfLongestSubstring1(s) << endl;
    }
    return 0;
}


/*
陌生知识点：
https://baike.sogou.com/v87712.htm?fromTitle=memset
遗忘知识点：
http://c.biancheng.net/view/488.html
debug问题：
https://blog.csdn.net/weixin_41803330/article/details/86742551
*/