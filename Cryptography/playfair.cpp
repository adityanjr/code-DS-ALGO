#include<iostream>
#include<cstring>
using namespace std;

char matrix[5][5], encrypt[20],plainText[20], decrypt[20];
int counter = 0,*j_present;

void playfair_encrypt(char c1, char c2){
    int x1,y1,x2,y2;
    if(c1 == 'j')
        c1 = 'i';
    if(c2 == 'j')
        c2 = 'i';
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j] == c1){
                x1 = i;
                y1 = j;
            }
            if(matrix[i][j] == c2){
                x2 = i;
                y2 = j;
            }
        }
    }

    if(x1 == x2){
        c1 = matrix[x1][(y1+1)%5];
        c2 = matrix[x2][(y2+1)%5];
        encrypt[counter++] = c1;
        encrypt[counter++] = c2;
    }
    else if(y1 == y2){
        c1 = matrix[(x1+1)%5][y1];
        c2 = matrix[(x2+1)%5][y2];
        encrypt[counter++] = c1;
        encrypt[counter++] = c2;
    }
    else{
        c1 = matrix[x1][y2];
        c2 = matrix[x2][y1];
        encrypt[counter++] = c1;
        encrypt[counter++] = c2;
    }
}

void playfair_decrypt(char c1, char c2){
    int x1,y1,x2,y2;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j] == c1){
                x1 = i;
                y1 = j;
            }
            if(matrix[i][j] == c2){
                x2 = i;
                y2 = j;
            }
        }
    }
    if(x1 == x2){
        c1 = matrix[x1][(y1-1)%5];
        c2 = matrix[x2][(y2-1)%5];
        decrypt[counter++] = c1;
        decrypt[counter++] = c2;
    }
    else if(y1 == y2){
        c1 = matrix[(x1-1)%5][y1];
        c2 = matrix[(x2-1)%5][y2];
        decrypt[counter++] = c1;
        decrypt[counter++] = c2;
    }
    else{
        c1 = matrix[x1][y2];
        c2 = matrix[x2][y1];
        decrypt[counter++] = c1;
        decrypt[counter++] = c2;
    }

}


int main(){
    int arr[26], m=0,n=0;
    for(int i=0;i<26;i++){
        arr[i] = 0;
    }

    char ch[50];

    // input the string
    cout<<"Enter a string:";
    cin>>ch;

    //skipping 'j'
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i] == 'j'){
            arr[ch[i] -97]= 1;
            continue;
        }
        if (arr[ch[i] - 97] == 0){
            arr[ch[i] -97]= 1;
            matrix[m][n] = ch[i];
            n++;
            if(n == 5){
                m++;
                n=0;
            }
        }
        else{
            continue;
        }
    }


    for(int i=0;i<26;i++){
        //for 'j'
        if(i == 9)
            continue;
        if(arr[i] == 0){
            //to fill rest of the matrix
            matrix[m][n] = i + 97;
            n++;
            if(n == 5){
                m++;
                n=0;
            }
        }
        else
            continue;
    }

    //printing the hill cipher matrix
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Enter a plain text to encrypt: ";
    cin>>plainText;

    int plainLen = strlen(plainText);

    //special case j
    j_present = new int[plainLen];
    for(int i = 0;i<plainLen;i++){
        if(plainText[i] == 'j')
            j_present[i] = 1;
        else
            j_present[i] = 0;
    }

    //shift for 'x'
    for(int i=0;i<plainText[i]!='\0';i+=2){
        if(plainText[i] == plainText[i+1]){
            char temp;
            int j;
            for(j=plainLen; j>i;j--)
                plainText[j+1] = plainText[j];
            plainText[i+1 ] = 'x';
        }
    }


    if(strlen(plainText)%2 != 0){
        plainText[plainLen] = 'x';
        plainText[plainLen+1] = '\0';
    }

    //dividing in pairs of 2
    char **separate = new char*[strlen(plainText)/2];
    for(int i=0;i<strlen(plainText)/2;i++){
        separate[i] = new char[3];
    }

    int z=0,x=0;
    for(int i=0;plainText[i]!='\0';i++){
        separate[z][x] = plainText[i];
        x++;
        if(x == 2){
            z++;
            x=0;
        }
    }


    for(int i=0;i<strlen(plainText)/2;i++)
        playfair_encrypt(separate[i][0],separate[i][1]);

    encrypt[counter] = '\0';
    cout<<"\nEncrypted: "<<encrypt;
    counter = 0;
    for(int i=0;encrypt[i]!='\0';i+=2)
        playfair_decrypt(encrypt[i], encrypt[i+1]);


    for(int i=0;i<decrypt[i]!='\0';i++){
        int j;
        if(decrypt[i] == 'x'){
            for(j=i;j<strlen(decrypt);j++)
                decrypt[j] = decrypt[j+1];
            decrypt[j] = '\0';
        }
    }

    for(int i=0;i<plainLen;i++){
        if(j_present[i] == 1)
            decrypt[i] = 'j';
    }
    cout<<"\ndecrypted: "<<decrypt;

    return 0;
}
