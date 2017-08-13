#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;

int main(){
	multimap<string,string>course;
	typedef multimap<string,string>::iterator courseiter;

	//插入课程上课时间
	course.insert(make_pair("c++","2-6"));
	course.insert(make_pair("compiler","3-1"));
	course.insert(make_pair("compiler","5-2"));
	course.insert(make_pair("os","1-2"));
	course.insert(make_pair("os","4-2"));
	course.insert(make_pair("os","5-5"));

	//查询上课时间
	string name;
	int count;
	do{
		cin>>name;
		count=course.count(name);
		if(count==0)
			cout<<"could not fond this course!"<<endl;
	}while(count==0);

	cout<<count<<"lesson(s) per week:";
	pair<courseiter,courseiter>range=course.equal_range(name);
	for(courseiter iter=range.first;iter!=range.second;++iter)
		cout<<(*iter).second<<" ";
	cout<<endl;

	return 0;
}