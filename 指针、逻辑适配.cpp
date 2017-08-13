#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool g(int x,int y){return x>y;}

int main(){
	int intarr[]={30,3,20,40,67,82,89,4,50};
	const int N=sizeof(intarr)/sizeof(int);
	vector<int>a(intarr,intarr+N);

	vector<int>::iterator iter;
    iter=find_if(a.begin(),a.end(),bind2nd(ptr_fun(g),40));
    if(iter==a.end())
    	cout<<"there is no element greater than 40"<<endl;
    else
    	cout<<"the first element greater than 40 is:"<<*iter<<endl;

    iter=find_if(a.begin(),a.end(),not1(bind2nd(ptr_fun(g),20)));
    if(iter==a.end())
        cout<<"there is no element not greater than 20"<<endl;
    else
        cout<<"first element not greater than 20 is :"<<*iter<<endl;

    iter=find_if(a.begin(),a.end(),bind2nd(not2(ptr_fun(g)),20));
	if(iter==a.end())
        cout<<"there is no element not greater than 20"<<endl;
    else
        cout<<"first element not greater than 20 is :"<<*iter<<endl;

    return 0;
}