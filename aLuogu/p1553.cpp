#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:


    void r1(string &a){
        reverse(a.begin(), a.end());
        if(!(a.length() == 1 && a[0] == '0')) {
            a.erase(0, a.find_first_not_of('0'));
            a.erase(a.find_last_not_of('0') + 1);
        }
    }

    string digitReverse(string &nb){
        int op = 0;
        if((op = nb.find('.')) != -1){
            string a = nb.substr(0, op);
            string b = nb.substr(op+1, nb.length() - op - 1);
            r1(a); r1(b);
            return a+"."+b;
        }else if((op = nb.find('/')) != -1){
            string a = nb.substr(0, op);
            string b = nb.substr(op+1, nb.length() - op - 1);
            r1(a); r1(b);
            return a+"/"+b;
        }else if((op = nb.find('%')) != -1){
            string a = nb.substr(0, op);
            r1(a);
            return a+"%";
        }else{
            r1(nb);
            return nb;
        }
    }
};



int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    cout<<Solution().digitReverse(a)<<endl;   
    return 0;
}