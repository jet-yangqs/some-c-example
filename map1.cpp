#include<iostream>
#include<map>
#include<cctype>

using namespace std;

int main(){
	map<char,int>s;
	char c;
	do{
		cin>>c;
		if(isalpha(c)){         //cctype中的功能函数，判断是否是字母
			c=tolower(c);    //所有字母转换为小写
			s[c]++;     //[]是map中重载的，执行后插入新元素，并且修改，查找元素的附加元素
		}
	}while(c!='.');

	for(map<char,int>::iterator iter1=s.begin();iter1!=s.end();iter1++)
		cout<<(*iter1).first<<":"<<(*iter1).second<<" ";

	return 0;
}