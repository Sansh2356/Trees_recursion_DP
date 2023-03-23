#include <iostream>
using namespace std;
class heap
{
public:
    int array[1000];
    int size;
    heap()
    {
        size = 0;
    }
    void insert(int data)
    {
        size = size + 1;
        int index = size;
        array[index] = data;
        // Parent comparison karte chalenge//
        while (index > 1)
        {
            int parent = index / 2;
            if (array[parent] < array[index])
            {
                swap(array[parent], array[index]);
                index = parent;
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
    void deleteheap()
    {
        array[1] = array[size];
        size--;
        int i = 1;
        while (i < size)
        {
            // i++;
            int parent = 2 * i;
            int left = 2 * i;
            int right = 2 * i + 1;
            if (array[i] < array[left])
            {
                i = left;
            }
            else if (array[i] < array[right])
            {
                i = right;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    heap heapobj;
    heapobj.insert(1);
    heapobj.insert(2);
    heapobj.insert(3);
    heapobj.insert(4);
    heapobj.print();
    cout << heapobj.size << endl;
    // 4//
}