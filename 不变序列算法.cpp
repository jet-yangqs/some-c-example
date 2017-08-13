#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

int main(){
	int intarr[]={0,0,1,2,3,4,4,5,6,6,6,7,8};
	vector<int>i(intarr,intarr+sizeof(intarr)/sizeof(int));
	int intarr1[]={6,6};
	vector<int>i1(intarr1,intarr1+sizeof(intarr1)/sizeof(int));
	int intarr2[]={5,6};
	vector<int>i2(intarr2,intarr2+sizeof(intarr2)/sizeof(int));
	int intarr3[]={0,1,2,3,4,5,6,7,7,7,8,9};
	vector<int>i3(intarr3,intarr3+sizeof(intarr3)/sizeof(int));

	//相邻两元素相等的第一个元素
	cout<<*adjacent_find(i.begin(),i.end())<<endl;
	
	//i中小于7的元素个数
	cout<<count_if(i.begin(), i.end(),bind2nd(less<int>(),7))<<endl;

	//i中大于2的第一个元素
	cout<<*find_if(i.begin(), i.end(),bind2nd(greater<int>(),2))<<endl;

	//i2在i中的起点元素
	cout<<*search(i.begin(), i.end(),i2.begin(), i2.end())<<endl;

	//连续出现3个6的起点位置元素
	cout<<*search_n(i.begin(), i.end(),3,6,equal_to<int>())<<endl;

	//判断i和i3是否相等
	cout<<equal(i.begin(), i.end(),i3.begin())<<endl;

	//i3和i不匹配点的位置
	pair<vector<int>::iterator,vector<int>::iterator> result=
	mismatch(i.begin(), i.end(),i3.begin());
    cout<<*result.first<<endl;
    cout<<result.first-i.begin()<<endl;
    //cout<<result.first-0<<endl;无意义
   // cout<<"位置上界上的元素："<<*(result.first-i.begin())<<endl;偏移量不再是指针，而是常数 

    return 0;
}