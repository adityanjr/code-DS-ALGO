#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    char str[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char key[30], msg[50],en_msg[50],de_msg[50];
    char keyMatrix[30];
    int arr[26], m = 0;
    for(int i=0;i<26;i++){
        arr[i] = 0;
    }

    cout<<"Enter a key: ";
    cin>>key;
    // converting key to keyMatrix
    for(int i=0;key[i]!='\0';i++){
        if(arr[key[i] - 97] == 0){
            arr[key[i] -97]= 1;
            keyMatrix[m] = key[i];
            m++;
        }
    }

    for(int i=0;i<26;i++){
        if(arr[i] == 0){
            keyMatrix[m] = i + 97;
            m++;
        }
    }
    keyMatrix[m] = '\0';
    m=0;

    cout<<"Enter a Message to encrypt: ";
    cin>>msg;

    cout<<"Key Matrix: "<<endl;
    for(int i=0;keyMatrix[i]!='\0';i++){
        cout<<keyMatrix[i]<<" ";
    }

    //encryption
    for(int i = 0;msg[i]!='\0';i++){
        en_msg[m++] = keyMatrix[msg[i] - 97];
    }

    en_msg[m] = '\0';
    m = 0;
    cout<<endl<<"Encrypted String: "<<en_msg<<endl;

    //Decryption
    for(int i=0;en_msg[i]!='\0';i++){
        int temp = 0;
        for(int j=0;j<26;j++){
            if(en_msg[i] == keyMatrix[j]){
                temp = j;
                break;
            }
        }
        de_msg[m++] = str[temp];
    }
    de_msg[m] = '\0';
    cout<<"Decrypted String: "<<de_msg;

    return 0;
}
