#include<bits/stdc++.h>

using namespace std;
int main()
{
    int number_of_words;
    cin>>number_of_words;
    char str[100];
    int a=0,b;
    int length;
    while(number_of_words--){
        cin>>str;
        length = strlen(str);
        if(length>10){
            a = (length-2)/10;
            b = (length-2)%10;
        if(a==0)
            cout<<str[0]<<b<<str[length-1]<<endl;
        else
           cout<<str[0]<<a<<b<<str[length-1]<<endl;
        }
        else
            cout<<str<<endl;
    }

    return 0;
}
