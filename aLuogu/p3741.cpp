#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    string str;
    int n;
    cin>>n;
    cin>>str;
    set<int> setv, setk, setvk;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'V' && i + 1 < n && str[i+1] == 'K'){
            cnt++;
            setvk.insert(i);
            setvk.insert(i+1);
            i++;
        }else{
            if(str[i] == 'V') setv.insert(i);
            if(str[i] == 'K') setk.insert(i);
        }
    }
    int flag = 0;
    for(int p: setv)
        if(p+1 != n && setvk.find(p+1) == setvk.end())
            flag = 1;
    for(int p: setk)
        if(p-1 >= 0 && setvk.find(p-1) == setvk.end())
            flag = 1;
            
    cout<<cnt+flag<<endl;        
    return 0;
}