#include <iostream>
#include <algorithm>
using namespace std;

/*
int main(){
//Heapify function to convert the tree into a heap//
void heapify(int array,int sizeofarray,int index){
  int largest=i;
  int left=2*i;
  int right=2*i+1;
  if(array[largest] < array[left] && left<size){
    largest = left;
  }
  if(array[largest] < array[right] && right<size){
    largest = right;
  }
  if(largest != i){
    swap(array[largest],array[i]);
    heapify(array,sizeofarray,largest);
  }

}
void heap(int array){
  int t=size-1;
  while(t >1){
    swap(array[1],array[t]);
    t--;
    heapify(array,sizeofarray,1);


  }
  int size = 0;

}
void insertinheap(int array[],int value){
  //Max_heap//
  //3,4,5//
int index = size+1;
array[index] = value;
while(index > 1){
  int parent = index/2;
if(array[index] > array[parent]){
swap(array[index],array[parent]);
index = parent;
else{
  return;
}
}
}
return;
}
}
 void deletionfromheap(int &array[],int arraysize){
  int index = arraysize-1;
  array[1] = array[index];
  size--;
  int t=1;
  while(t > size){
    int largest = t;
    int left = 2*t;
    int right = 2*t+1;
    if(array[left] > array[largest] && left <size){
      largest = left;
    }
    if(array[right] > array[largest] && right <size){
      largest = right;
    }
    else{
      return;
    }
  
  }
 }
*/
int main(){
 //Q)To find the Kth smallest element in a given array//
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here//
     priority_queue<int>pq;
     for(int i=0;i<k;i++){
         pq.push(arr[i]);
     }
     //Priority queue has been created and then the comparison will take place//
     for(int m =k ; m<=r;m++){
         if(pq.top() > arr[m]){
             pq.pop();
             pq.push(arr[m]);
         }
     }
     int ans = pq.top();
     return ans;
     
    
    //Earlier solution was a solution of time and space complexity of nlogn
    //But this particular solution is of 
}