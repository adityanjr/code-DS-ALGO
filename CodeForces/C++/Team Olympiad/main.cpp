#include <iostream>
#include<cmath>
using namespace std;

int main()
{   int counter_one=0,counter_two=0,counter_three=0;
    int one[5000],two[5000],three[5000];
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1)
            one[counter_one++]=i+1;
        else if(a==2)
            two[counter_two++]=i+1;
        else
            three[counter_three++]=i+1;
    }
    int size_one,size_two,size_three;
    size_one = counter_one;
    size_two = counter_two;
    size_three = counter_three;
    if((size_one<=size_two)&&(size_one<=size_three)){
        cout<<size_one<<endl;
        if(size_one==0)
            exit(0);
        else{
            for(int i=0;i<size_one;i++){
                cout<<one[i]<<" "<<two[i]<<" "<<three[i]<<endl;
            }
        }
    }
    else if((size_two<=size_one)&&(size_two<=size_three)){
        cout<<size_two<<endl;
        if(size_two==0)
            exit(0);
        else{
            for(int i=0;i<size_two;i++){
                  cout<<one[i]<<" "<<two[i]<<" "<<three[i]<<endl;
            }
        }
        }
    else if((size_three<=size_one)&&(size_two>=size_three)){
        cout<<size_three<<endl;
        if(size_three==0)
            exit(0);
        else{
            for(int i=0;i<size_three;i++){
                cout<<one[i]<<" "<<two[i]<<" "<<three[i]<<endl;
            }
        }
    }
    else {
        cout<<size_one<<endl;
        for(int i=0;i<size_three;i++){
                cout<<one[i]<<" "<<two[i]<<" "<<three[i]<<endl;
            }
    }

    return 0;
}
