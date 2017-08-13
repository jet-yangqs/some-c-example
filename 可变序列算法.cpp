#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<functional>

using namespace std;

class evenbytwo{
private:
	int x;
public:
	evenbytwo():x(0){}
	int operator()(){return x+=2;}
};

int main(){
	int iar1[]={0,1,2,3,4,5,5,5,6,6,7,8,9,9,9};
	int iar2[]={0,1,2,3,4,5,6,7,8,9,9,9};
    vector<int>ivec1(iar1,iar1+sizeof(iar1)/sizeof(int));
    vector<int>ivec2(iar2,iar2+sizeof(iar2)/sizeof(int));
    vector<int>ivec3(2);

    fill(ivec3.begin(),ivec3.end(),-1);   //-1填充ivec3
    copy(ivec3.begin(), ivec3.end(),ostream_iterator<int>(cout," "));  //输出ivec3
    cout<<endl;

    generate(ivec3.begin(), ivec3.end(),evenbytwo());   //ivec3每个元素都加2
    copy(ivec3.begin(), ivec3.end(),ostream_iterator<int>(cout," "));  //输出ivec3
    cout<<endl;

    vector<int>ivec4;
    remove_copy(ivec2.begin(),ivec2.end(),back_inserter(ivec4),6); //删除6，并将新序列放置于容器ivec4
    copy(ivec4.begin(), ivec4.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    ivec2.erase(remove_if(ivec2.begin(), ivec2.end(),bind2nd(less<int>(),6)),ivec2.end());   //move_if 返回一个迭代器，作为erase的起始位置
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    replace(ivec2.begin(), ivec2.end(),6,3);    //3取代6
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    reverse(ivec2.begin(), ivec2.end());   //反向
    copy(ivec2.begin(), ivec2.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    rotate_copy(ivec2.begin(), ivec2.begin()+3,ivec2.end(),ostream_iterator<int>(cout," "));  //两个区间元素颠倒，直接输出
    cout<<endl;

    return 0;
}
