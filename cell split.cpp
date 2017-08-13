#include<iostream>
#include<queue>
#include<cstdlib>
#include<ctime>

using namespace std;

const int tmin=500;   //最短最长分裂时间
const int tmax=2000;

class cell;
priority_queue<cell> cellqueue;

class cell{
private:
	static int count;  //细胞计数
	int id;          //当前编号
	int time;       //分裂时间
public:
	cell(int birth):id(count++){             //初始化，birth为细胞诞生时间
		time=birth+(rand()%(tmax-tmin))+tmin;
	}
	int getid() const{return id;}
	int getsplitetime() const{return time;}
    bool operator<(const cell& s) const{return time>s.time;}   //重载<
    
    void split(){    //细胞分裂
        cell child1(time),child2(time);
        cout<<time<<"s:cell #"<<id<<"split to #"
        <<child1.getid()<<"and #"<<child2.getid()<<endl;
        cellqueue.push(child1);
        cellqueue.push(child2);   //压入优先队列
    }

};

int cell:: count=0;

int main(){
	srand(static_cast<unsigned>(time(NULL)));
	int t;
	cout<<"simulation time:";
	cin>>t;
	cellqueue.push(cell(0));
	while(cellqueue.top().getsplitetime()<=t){
		cellqueue.top().split();                 //细胞分裂并将两个子细胞压入
		cellqueue.pop();                         //删除已经分裂完成的细胞
	}

return 0;
}