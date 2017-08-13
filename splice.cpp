#include<iostream>
#include<list>
#include<iterator>
#include<string>

using namespace std;

int main(){
	string name1[]={"alice","helen","lucy","susan"};
	string name2[]={"bob","david","levin","mike"};
	list<string> s1(name1,name1+4);
	list<string> s2(name2,name2+4);   //用数组元素构造列表

	s2.splice(s2.end(),s1,s1.begin());   //将s1的第一个元素插入s2的最后
	list<string>::iterator iter1=s1.begin();  //iter1指向s1首
	advance(iter1,2);   //iter1将前进2个元素，指向是s1的第三个元素
	list<string>::iterator iter2=s2.begin();   //iter2指向s2首
	++iter2;   //iter2前进一个元素，指向s2的第二个元素
	list<string>::iterator  iter3=iter2;
	advance(iter3,2);   //iter3指向s2的第四个元素

	s1.splice(iter1,s2,iter2,iter3);  //s2中[iter2,iter3)区间元素接到iter1和iter1-1之间，删除原列表中的该区间元素
    
    copy(s1.begin(),s1.end(),ostream_iterator<string>(cout," "));    //输出s1,s2
    cout<<endl;
    copy(s2.begin(),s2.end(),ostream_iterator<string>(cout," "));
    cout<<endl;
	//cout<<*(s1.end()--);

    return 0;
}