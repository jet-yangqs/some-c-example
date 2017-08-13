#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>

using namespace std;

int main(){
	int iarr[]={1,2,3,4,5};
	vector<int>ivec(iarr,iarr+sizeof(iarr)/sizeof(int));

    cout<<accumulate(ivec.begin(), ivec.end(),0)<<endl;  //向量和累计

    cout<<inner_product(ivec.begin(), ivec.end(),ivec.begin(),10)<<endl;

    vector<int>ivec1(5);
    partial_sum(ivec.begin(), ivec.end(),ivec1.begin());
    copy(ivec1.begin(), ivec1.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    adjacent_difference(ivec.begin(), ivec.end(),ivec1.begin());
    copy(ivec1.begin(), ivec1.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    return 0;
}
