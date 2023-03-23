#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    bool ans = true;
    string a = "abba";
    string b = "dog cat cat dog";
    string empty = "";
    map<char, string> m;
    int index = 0;
    int k = 0;
    for (int x = 0; x < a.size(); x++)
    {
        empty = "";
        for (k; k < b.size(); k++)
        {
            if (b[k] != ' ')
            {
                empty.push_back(b[k]);
            }
            if (b[k] == ' ')
            {
                index = k;
                break;
            }
        }
        k = index + 1;
        // Before entry we will have to check//
        // If the entry is already there or not//
        if (m.count(a[x]) == 0)
        {
            m[a[x]] = empty;
        }
        if (m.count(a[x]) != 0 && m[a[x]] != empty)
        {
            ans = false;
            return ans;
        }
        if (m.count(a[x]) != 0 && m[a[x]] == empty)
        {
            continue;
        }
    }
    // Mapping has been created for characters of a and the substrings of b//
    string newstring = "";
    for (int s = 0; s < a.size(); s++)
    {
        newstring = newstring + m[a[s]];
        if (s < a.size() - 1)
        {
            newstring.push_back(' ');
        }
    }
    for (int j = 0; j < b.size(); j++)
    {
        for (int h = 0; h < newstring.size(); h++)
        {
            if (b[j] != newstring[h])
            {
                ans = false;
                return false;
            }
        }
    }
}