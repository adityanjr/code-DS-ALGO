#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string time;
    cin>>time;
    string zone = time.substr(8);
    
    if(zone == "AM"){
        if(time.substr(0,2)=="12"){
            cout<<"00"<<time.substr(2,6);
        }
        else{
            cout<<time.substr(0,8);
        }
    }
    else {
        if (time.substr(0,2) == "12")
            cout << time.substr(0,8);
        else
        {
            int val = (time[0] - '0')*10 + (time[1]-'0');
            val += 12;
            cout<<val<<time.substr(2,6);
        }
    }
}