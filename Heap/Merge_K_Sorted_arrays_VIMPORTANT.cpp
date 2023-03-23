#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
//Q)To merge K sorted arrays into a single sorted array in OPTIMIZED TIME AND SPACE COMPLEXITY//
int main(){
    /*
    To create additional node containing data of node,index of column and index of row
    Insert the first index of the given term in min heap 
    Iteratively moving throughout the queue and pushing the values of different nodes iniside the vector and passing on appropriate values of column and rows iteratively//
    
    */
    unordered_map<int,int>m;   
    pair<int,int>p;
    int array[11]{0 ,-5, -2, -4, 2, -2, -3, -1, -1, -3, 0};

    ndex.insert(temp);
        }
    }

    for(int l=0;l<11;l++){
        int t=array[l];
        if(m.count(t) == true){
            m.at(t)++;
        }
        else{
            p.first = t;
            p.second = 1;
            m.insert(p);
        }
    }
    
    int max = 0;
    int returnAns = array[0];

    for(auto i:m){
        if(i.second > max) {
            returnAns = i.first;
            max = i.second;
        }else if (i.second == max)
        {
            if(index[i.first] < index[returnAns]){
                returnAns = i.first;
            }
        sort(array,array+n)
        }
        
    }

    cout << "Max value is " << returnAns << " which was found " << max << " times" << endl;
}unordered_map<int,int> index;

    for(int l=0;l<11;l++){
        int t=array[l];
        if(index.count(t) != true){
            pair<int,int> temp;
            temp.first = t;
            temp.second = l;
            i



