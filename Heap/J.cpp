#include<iostream>
#include<queue>
using namespace std;
/*
void heapify(int array[],int index,int sizeofarray){
    int largest = index;
    int left = 2*index;
    int right = 2*index +1;
    if(array[left] > array[largest] && left < sizeofarray){
        largest = left;
    }
    if(array[right] > array[largest] && right < sizeofarray){
        largest = right;
    }
    if(largest != index){
        swap(array[largest],array[index]);
        heapify(array,largest,sizeofarray);
    }
}
int main(){
    for(int m=n/2;m>=0;m--){
        heapify(array,m,sizeofarray);
    }
    
    }
    

*/
//Convert BST to min heap//
int main(){
    priority_queue<int>pq;
    int array[5]{1,2,6,4,3};
    vector<int>v;
    for(int m=0;m<5;m++){
        int sum=array[m];
        v.push_back(sum);
        for(int k=m+1;k<5;k++){
            sum=sum+array[k];
                v.push_back(sum);
        }
       
    }
    for(int x=0;x<v.size();x++){
            pq.push(v[x]);
    }
    int count=0;
    int k;
    while(pq.size() != 0 && count == k){
        pq.pop();

    }
    return pq.top();


   


}