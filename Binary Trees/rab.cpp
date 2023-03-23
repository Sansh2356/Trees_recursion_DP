#include <iostream>
#include <queue>
using namespace std;
void sum(int &a,int &b){
    swap(a,b);
    cout<<a<<" "<<b<<endl;
}
int main(){
    int a,b;
    cin>>a>>b;
    sum(a,b);
    cout<<a<<" "<<b<<endl;
}