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
int main(){
    //Heap sort//
    /*
    Swapping of first term with the last term after the heapify has already acted on a  given tree to create a given tree//
    Then to decrease the size of array by 1
    Calling the heapify function in order to get the assigned root node to its correctly assigned position//
    void heapsort(int array[]){
        int t= size;
        while(t<1){
            swap(array[1],array[t]);
            t--;
            //After swapping we will have to ensure the correct position of the inseerted root node at the top//
            heapify(array,size,1);
            Time complexity will be equal to = Nlog(N)
            
        }
    }
    */
}
/*
Creation of max_heap and min_heap can be done by using the STL of c++ named as priority queue
Importing queue from the header files
min_heap creation
priority_queue<int,vector<int>,greater<int>>name;
*/