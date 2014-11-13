#include <iostream>
#include <cstring>
#include <string.h>
#define max 100

using namespace std;

int LCS(int, int, string, string);
void printPath(int, int, string, string);

int direction[max][max];
int cache[max][max];

int LCS(int p, int q, string s1, string s2)
{
    if (p == -1 || q == -1) {
        return 0;
    }
    if (cache[p][q] != -1) {
        return cache[p][q];
    }
    if (s1[p] == s2[q]) {
        direction[p][q] = 0;
        cache[p][q] = 1 + LCS(p-1, q-1, s1, s2);
        return cache[p][q];
    }
    else
    {
        int v1 = LCS(p-1, q, s1, s2);
        int v2 = LCS(p, q-1, s1, s2);
        if (v1 > v2) {
            direction[p][q] = 1;
            cache[p][q] = v1;
        }
        else
        {
            direction[p][q] = 2;
            cache[p][q] = v2;
        }
        return cache[p][q];
    }
}
void printPath(int p, int q, string s1, string s2)
{
    if (p == -1 || q == -1) {
        return;
    }
    if (direction[p][q] == 0) {
        printPath(p-1, q-1, s1, s2);
        cout<<s1[p];
    }
    else if (direction[p][q] == 1)
    {
        printPath(p-1, q, s1, s2);
    }
    else if (direction[p][q] == 2)
    {
        printPath(p, q-1, s1, s2);
    }
}
int main()
{
    string s1,s2;
    cout<<"Please input the first string:"<<endl;
    cin>>s1;
    cout<<"Please input the second string:"<<endl;
    cin>>s2;
    int len1 = int(s1.size());
    int len2 = int(s2.size());
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            direction[i][j] = -1;
            cache[i][j] = -1;
            
        }
    }
    int len = LCS(len1, len2, s1, s2);
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            cout<<direction[i][j]<<" ";
            
        }
        cout<<endl;
    }
    cout<<"The length of LCS is:"<<len-1<<endl;
    cout<<"LCS is:"<<endl;
    printPath(len1, len2, s1, s2);
    cout<<endl;
    return 0;
}
