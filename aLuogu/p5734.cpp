#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    char str[1000], apd[100], ins[100], t[100];
    
    int q, op;
    cin>>q;
    cin>>str;
    for(int c = 0; c < q; c++){
        cin>>op;
        if(op == 1){
            char *p = str, *t_;
            while (*p != '\0') p++;
            cin>>apd;
            t_ = apd;
            while(*t_ != '\0') *(p++) = *(t_++);
            *p = '\0';
            cout<<str<<endl;
        }else if(op == 2){
            int a, b;
            cin>>a>>b;
            int i = 0;
            for(; i < b; i++){
                str[i] = str[i+a];
            }
            str[i] = '\0';
            cout<<str<<endl;
        }else if(op == 3){
            int pos, i;
            cin>>pos>>ins;
            for(i = pos; str[i] != '\0'; i++) t[i - pos] = str[i];
            t[i - pos] = '\0';
            for(i = pos; ins[i - pos] != '\0'; i++) str[i] = ins[i - pos];
            int k = i;
            for(; t[k - i] != '\0'; k++) str[k] = t[k - i];
            str[k] = '\0';
            cout<<str<<endl;
        }else if(op == 4){
            string fd;
            string t(str);
            cin>>fd;
            int a = t.find(fd);
            cout<<a<<endl;
        }
    }  
    return 0;
}