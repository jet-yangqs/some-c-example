#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;

int main(){
	map<string,int>course;  //声明map变量
    course.insert(make_pair("csapp",3));  //make_pair把字符串和整数的两个元素转换为一个二元组
    course.insert(make_pair("c++",2));
    course.insert(make_pair("csarch",4));
    course.insert(make_pair("compiler",4));
    course.insert(make_pair("os",3));

    int n=3;
    int sum=0;
    string name;
    while(n>0){
        cin>>name;
    	map<string,int>::iterator iter=course.find(name);
    	if(iter=course.end())
    		cout<<"there are no "<<name<<"course"<<endl;
    	else{
            sum+=(*iter).second;
            course.erase(iter);
            n--;
    	}
    }
    cout<<"the total credit:"<<sum<<endl;
    
    return 0;
}