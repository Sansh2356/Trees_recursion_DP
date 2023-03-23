// Heap is a ds which is a complete binary tree with every node entry from the left side but the lest level can be left without beingfully filled//
#include <iostream>
using namespace std;
// insertion in heap that will be done in two steps-:
// 1)The insertion of value of node in end of array//
// 2)The first entry will be not be filled in array//
// 3)Finding the correct position of the data enetered that will be done by recursive calls and max heap or min heap property//
// 4)Locating parent,left and right node of the given node by parent given by index/2,2*index for left child,2*index+1 for right child//
class heap
{
public:
    int array[100];
    int size;
    heap()
    {
        this->size = 0;
    }
    // Insertion in heap//
    void insert(int data)
    {
        size = size + 1;
        int index = size;
        array[index] = data;
        while (index > 1)
        {
            // Check for correct position//
            if (array[index / 2] < array[index])
            {
                swap(array[index / 2], array[index]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }
    // Deletion from heap//
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
                i = 2 * i;
            }
            else if (array[2 * i + 1] > array[i] && (2 * i + 1 < size))
            {
                swap(array[2 * i + 1], array[i]);
                i = 2 * i + 1;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << array[i] << endl;
        }
    }
};

int main()
{
    heap heapobject;
    heapobject.insert(1);
    heapobject.insert(2);
    heapobject.insert(3);
    heapobject.insert(4);
    heapobject.print();
    heapobject.deletefromheap();
    heapobject.print();
    /*
    insert(34);
    void insert(int array[],int sizeofarray){
        int index = 1;
        array[index] = data;
        int i=1;
        while(i > size){

            if(){

            }
        }
    }
    
    
    */
}
