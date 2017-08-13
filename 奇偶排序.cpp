//sort.cpp
#include<vector>
#include<deque>
#include<algorithm>
#include<iterator>
#include<iostream>

using namespace std;
 int main(){
 	istream_iterator<int> i1(cin),i2;  //建立一对输入流迭代器
 	vector<int>s1(i1,i2);   //通过迭代器构造向量s1
 	sort(s1.begin(),s1.end());  //对输入的整数排序
    deque<int>s2;  //deque可以高效从两端插入

    //遍历s1
    for(vctor<int>::iterator iter=s1.begin(); iter!=s1.end();++iter){
    	if(*iter%2==0)
    		s2.push_front(*iter);   //偶数从小到大
    	else
    		s2.push_back(*iter);    //奇数从大到小
    }
    copy(s2.begin(),s2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
 }