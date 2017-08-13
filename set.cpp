#include<iostream>
#include<set>
#include<iterator>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
	set<double>s;
	while(true){
		double v;
		cin>>v;
        if(v==0)  break;
        pair<set<double>::iterator,bool>r=s.insert(v);  //插入v，并且将返回值付给pair r
        if(!r.second)                                //判断r中的bool值，false则输出重复提示
        	cout<<v<<" is duplicated."<<endl;
	}

	set<double>::iterator iter1=s.begin();
	set<double>::iterator iter2=s.end();
	double medium=(*iter1+*iter2)/2;

	//输出小于中值的元素
	cout<<"element <= medium:\n";
	copy(s.begin(),s.upper_bound(medium),ostream_iterator<double>(cout," "));
	cout<<endl;

	//输出大于等于中值
	cout<<"element >= medium:\n"<<endl;
	copy(s.lower_bound(medium),s.end(),ostream_iterator(cout," "));
	cout<<endl;

	return 0;
}
