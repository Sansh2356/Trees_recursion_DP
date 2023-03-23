#include<iostream>
#include<vector>
using namespace std;
void blah(vector<int>&v){
v.push_back(12);
v.push_back(13);
}
int main(){
vector<int>v;
blah(v);
cout<<"Value is ::"<<v[0]<<endl;
}