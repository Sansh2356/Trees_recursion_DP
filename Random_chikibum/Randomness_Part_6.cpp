#include<iostream>
using namespace std;
class heap{
    public:
    int array[100];
    int sizeofarray;
    heap(){
        sizeofarray = 0;
    }
    void insertinheap(int data){
        sizeofarray=sizeofarray+1;
        int index=sizeofarray;
        array[index] = data;
        while(index > 1){
            int parent=index/2;
            if(array[parent] < array[index]){
                swap(array[parent],array[index]);
                index=parent; 
            }
            else{
                return;
            }
        }       
    }
    void deletenode(){
        array[sizeofarray-1] = array[1];
        sizeofarray--;
        int n=1;
        while(n > sizeofarray){
                int left=2*n;
                int right=2*n+1;
                if(array[left] > array[n] && left<sizeofarray){
                    swap(array[left],array[n]);
                    n=left;
                }
                else if(array[right] > array[n] && right<sizeofarray){
                    swap(array[right],array[n]);
                    n=right;
                }
                else{
                    return;
                }
                
        }
    }
    void heapify(){
        
    }
};
int main(){

}