#include<map>
#include<vector>
#include<iostream>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
            //Write your code here//
     
    map<int,int>m;
    map<int,int>map2;
    pair<int,int>indexpair;
    pair<int,int>p;
    for(int b=0;b<n;b++){
       
        if(map2.count(arr[b]) == true){
            continue;
        }
        else{
            indexpair.first = arr[b];
            indexpair.second = b;
            map2.insert(indexpair);
        }
    }
    
    for(int l=0;l<n;l++){
        int t=arr[l];
        if(m.count(t) == true){
            m.at(t)++;
        }
        else{
            p.first = t;
            p.second = 1;
            m.insert(p);
        }
    }

    cout << "MAP2" << endl;

    for(auto x : map2){
        cout << x.first << " : " << x.second << endl;
    }

    cout << "\n" << "Count" << endl;

    for(auto x : m){
        cout << x.first << " : " << x.second << endl;
    }

    int max=-1;
    int max_value=arr[0];
//     cout<<max_value<<"sjsd"<<endl;
    for(auto i:m){
        if(i.second > max){
            max_value = i.first;
            max = i.second;
        }
        else if(i.second == max){
            int a = map2.at(i.first);
            int b = map2.at(max_value);
            if(a < b){
                max_value = i.first;         
            }
        }
    }
    
    int ans = max_value;
    return ans;
}


int main(){
    vector<int> x = {0,-5,-2,-4,2,-2,-3,-1,-1,-3};
    cout << maximumFrequency(x,x.size());
}