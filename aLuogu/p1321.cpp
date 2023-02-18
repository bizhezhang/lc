#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    int boy = 0, girl = 0, pos;
    while((pos = str.find("girl"))!=-1) str[pos] = str[pos+1] = str[pos+2] = str[pos+3] = '.',girl++;
    while((pos = str.find("gir"))!=-1||(pos = str.find("irl"))!=-1) str[pos] = str[pos+1] = str[pos+2] = '.', girl++;
    while((pos = str.find("gi"))!=-1||(pos = str.find("ir"))!=-1||(pos = str.find("rl"))!=-1) str[pos] = str[pos+1] = '.', girl++;
    while((pos = str.find("g"))!=-1||(pos = str.find("i"))!=-1||\
    (pos = str.find("r"))!=-1||(pos = str.find("l"))!=-1) str[pos] = '.', girl++;
    while((pos = str.find("boy"))!=-1) str[pos] = str[pos+1] = str[pos+2] = '.',boy++;
    while((pos = str.find("bo"))!=-1||(pos = str.find("oy"))!=-1) str[pos] = str[pos+1] = '.',boy++;
    while((pos = str.find("b"))!=-1||(pos = str.find("o"))!=-1||\
    (pos = str.find("y"))!=-1) str[pos] = '.',boy++;
    cout<<boy<<endl<<girl<<endl;
    return 0;
}