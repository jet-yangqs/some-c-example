#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int intarr[]={30,40,90,60,28,49,60,40};
    const int N=sizeof(intarr)/sizeof(int);

    vector<int>a(intarr,intarr+N);
    vector<int>::iterator iter=find_if(a.begin(),a.end(),bind2nd(greater<int>(),40));
     if(iter==a.end)
     	cout<<"there is no element greater than 40!"<<endl;
     else
     	cout<<"the first element greater than 40 is:"<<*iter<<endl;

     return 0;
}
