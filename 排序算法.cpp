#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){
	int iarr[]={13,12,26,34,24,24,35,46,74,68,93,45};
	vector<int> ivec(iarr,iarr+sizeof(iarr)/sizeof(int));

	vector<int>::iterator iter=max_element(ivec.begin(), ivec.end());    //找到最大元素输出元素和位置
	cout<<"the max element is :"<<*iter<<" found at "<<iter-ivec.begin()<<endl;

    vector<int> ivec1(5);
    partial_sort_copy(ivec.begin(), ivec.end(),ivec1.begin(), ivec1.end());   //局部排序复制到新的容器后输出，复制的个数由目标容器容量决定
    copy(ivec1.begin(),ivec1.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    sort(ivec.begin(), ivec.end());    //默认递增排序
    copy(ivec.begin(), ivec.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    cout<<*lower_bound(ivec.begin(), ivec.end(),24)<<endl;  //输出小于等于和大于等于24的位置迭代器，*后输出元素
    cout<<*upper_bound(ivec.begin(), ivec.end(),24)<<endl;

    cout<<binary_search(ivec.begin(), ivec.end(),24)<<endl;   //二分法查找元素
    cout<<binary_search(ivec.begin(), ivec.end(),15)<<endl;

    vector<int> ivec2(17),ivec3(10);
    merge(ivec.begin(), ivec.end(),ivec1.begin(), ivec1.end(),ivec2.begin());    //ivec和ivec1合并后放到ivec2,ivec3,ivec3会报错，超出范围;merge是合并，一般在元素有序时使用
   // merge(ivec.begin(), ivec.end(),ivec1.begin(), ivec1.end(),ivec3.begin());
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
   // copy(ivec3.begin(), ivec3.end(),ostream_iterator<int>(cout," "));
    //cout<<endl;
	
    nth_element(ivec2.begin(), ivec2.begin()+5,ivec2.end());     //小于ivec2.begin()+5位置的元素放在左边，其余留在右边，不保证原始排序
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    stable_sort(ivec2.begin(), ivec2.end());    //保持相同元素的相对位置
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    int iarr4[]={1,3,5,7,2,4,6};
    vector<int> ivec4(iarr4,iarr4+sizeof(iarr4)/sizeof(int));
    copy(ivec4.begin(), ivec4.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    inplace_merge(ivec4.begin(),ivec4.begin()+4, ivec4.end());         //一定要保证middle前后两个序列都是有序的，才能合并
    copy(ivec4.begin(), ivec4.end(),ostream_iterator<int>(cout," "));
    cout<<endl;  

    return 0;
}

