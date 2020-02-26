/* 
来源：算法经典面试题
类属：数据结构
序号：0-数组
*/
/*
题目：两数之和：用了小技巧
描述：给定一个整数数组、一个目标值，找出数组中 和为目标值的 两个数。
假设，每个输入只对应一种答案，且同样的元素不能被重复利用。
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>

using namespace std;

class solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        // 已知：a+b=target;  求：a的位置、b的位置 =》 key-value  = 【b ， a的位置】 。
        /* 分析：
            三元素中，target定，逐个扫描数组元素为a，对应记为a的位置 = value；可以算得 b = target-a，b存为对应的键key值。
            所有的key值构成了hash-table，接下来就是找符合条件的b值，即可通过扫描hash-table找。
            因为本题目只有唯一一个答案，因此，找到后即可break；找不到就继续扩增key-value。
            找到后，把当前b/key对应的value即a的位置先push到结果中；接着，把当前找到的b值的位置push到结果中。
            解题完成。
        */
        unordered_map<int,int> m;       // hash_table： key-value  = 【b ， a的位置】 
        vector<int> result;            
        for(int i=0; i<numbers.size(); i++){
            // 没找到第二个
            if( m.find(numbers[i]) == m.end() ){        // m容器中搜索numbers[i]，相等表示没有找到，因为返回了迭代器的最末端。
                // 存储第一个的位置到第二个的key中  
                m[target-numbers[i]] = i;
            }
            else{
                //  找到第二个
                result.push_back(m[numbers[i]]);       // 第一个的value值
                result.push_back(i);                // 第二个
                break;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    int target;
    int n;
    while(cin.peek()!='\n'){ 
        cin>>n;
        nums.push_back(n);
    }
    cin >> target;

    solution s;
    vector<int> result = s.twoSum(nums, target);  
    cout << result[0] << ' ' << result[1] << endl;
    return 0;
}


/*
陌生知识点：
http://c.biancheng.net/view/526.html
https://blog.csdn.net/qq_26822029/article/details/79377730
https://zhuanlan.zhihu.com/p/48066839
疑难：
https://blog.csdn.net/flora_zhl/article/details/51378813
https://blog.csdn.net/Jamence/article/details/55505689?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
https://jingyan.baidu.com/article/60ccbcebad34e964cab19720.html
*/