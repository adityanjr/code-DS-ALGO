#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    int holes[26]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
    //             A B C D E F G H I J K L M N O P Q R S T U V W X Y Z;

    string input;
    size_t N,output; 

    scanf("%zd\n",&N);
    for(size_t k = 0; k < N ;k++){
        getline(cin,input);
        output =0;
        for(size_t m = 0; m < input.size(); m++){output += holes[ input[m]-'A'];}
        cout << output << endl;
    }
    return 0;
}
