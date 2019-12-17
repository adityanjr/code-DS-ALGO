#include <iostream>
using namespace std;
void towerofhanoi(int n, char source, char helper, char destination){
    if(n==0)
        return;
    towerofhanoi(n-1,source,destination,helper);
    cout<<"Move "<<n<<" to "<<destination<<endl;
    towerofhanoi(n-1,helper,source,destination);
}
int main()
{    int n;
     cin>>n;
     towerofhanoi(n,'A','B','C');
     return 0;
}
