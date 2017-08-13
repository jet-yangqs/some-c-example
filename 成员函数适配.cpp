#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct car{
	int id;
	car(int id){this->id=id;}
	void display() const{cout<<"car"<<id<<endl;}
};

int main(){
	vector<car*>pcars;
	vector<car>cars;
	for(int i=0;i<5;i++)
		pcars.push_back(new car(i));
	for(int i=5;i<10;i++)
		cars.push_back(car(i));

	cout<<"element in pcars:"<<endl;
	for_each(pcars.begin(), pcars.end(),mem_fun(&car::display));
	cout<<endl;

	cout<<"element in cars:"<<endl;
	for_each(cars.begin(),cars.end(),mem_fun_ref(&car::display));
	cout<<endl;

	for(size_t i=0;i<pcars.size();i++)
		delete pcars[i];

	return 0;
}