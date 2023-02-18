#include <bits/stdc++.h>
using namespace std;
#define N 201

int main(int argc, char const *argv[])
{

    char a[N][N];
    gets(a[0]);
    int nn = 0;
    while(a[0][nn] == '1' || a[0][nn] == '0') nn++;
    for(int k = 0; k < nn-1; k++) gets(a[k+1]);
    cout<<nn<<" ";
    int f = 0, c = 0;
    for(int k = 0; k < nn; k++){
        for(int i = 0; i < nn; i++){
            if(!f){
                if(a[k][i]-'0' == 0) c++;
                else {
                    cout<<c<<" ";
                    c=f=1;
                }
            }else{
                if(a[k][i]-'0' == 1) c++;
                else{
                    cout<<c<<" ";
                    f=0;c=1;
                }
            }
        }
    }
    cout<<c<<endl;
    return 0;
}
