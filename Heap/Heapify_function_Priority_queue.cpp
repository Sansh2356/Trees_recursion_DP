//Heapify function will form or convert the entire subtree given from a certain index uptill the leaf node into a heap//
#include<iostream>
using namespace std;
class heap
{
public:
    int array[100];
    int size;
    heap()
    {
        this->size = 0;
    }
    //Insertion in heap//
    void insert(int data)
    {
        size=size+1;
        int index=size;
        array[index] = data;
        while (index > 1)
        {
            // Check for correct position//
            if (array[index / 2] < array[index])
            {
                swap(array[index / 2], array[index]);
                index = index/2;
            }
            else
            {
                return;
            }
            
        }
    }
    //Deletion from heap//
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "Nothing can be deleted" << endl;
            return;
        }
        // Step 1)To replace the values of the root node and the last node//
        // Step 2)To delete the last node//
        // Step 3)To assign the accurate position of the root node in the heaptree//
        // Step-1)//
        array[1] = array[size];
        // Step-2)//
        size--;
        int i = 1;
        // Step-3)//
        while (i < size)
        {
            // Comparison//
            if (array[2 * i] > array[i] && 2 * i < size)
            {
                swap(array[2 * i], array[i]);
                i=2*i;
            }
            else if (array[2 * i + 1] > array[i] && (2 * i + 1 < size))
            {
                swap(array[2 * i + 1], array[i]);
                i=2*i+1;
            }
            else
            {
                return;
            }
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<array[i]<<endl;
        }
    }
};
//Heapify function to convert an input array to heap below a given index a//
void heapify(int array[],int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
//Comparison with left and right child to ensure max_heap throughtout the given tree//
if(array[largest] < array[left] && left <n){
   
    largest = left; 
}
 if(array[largest] < array[right] && right <n){
    
    largest = right; 
}
if(largest != i){
    swap(array[largest],array[i]);
    //Recursive call untill the entire sub-tree below the given index gets converted into a heap//
    heapify(array,n,largest);
}



}
int main(){
    heap heapobject;
    // heapobject.insert(1);
    // heapobject.insert(2);
    // heapobject.insert(3);
    // heapobject.insert(4);
    int array[6]{-1,2,3,6,7,9};
    int n=5;
    int i;
    for(int i=n/2;i>0;i--){
        heapify(array,n,i);
    }
    for(int j=1;j<6;j++){
        cout<<array[j]<<" ";
    }
    cout<<endl;
}