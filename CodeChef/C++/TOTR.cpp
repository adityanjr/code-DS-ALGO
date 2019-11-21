#include <iostream>
using namespace std;

int main(){

    string message = "";  int offset = 0; char output = 'a';
    int numCases; scanf("%d ",&numCases);
    string trans; getline(cin, trans);

    while(numCases--){
        getline(cin, message);
        for(size_t k = 0; k < message.size(); k++){
            if(message[k] >= 'a' && message[k] <= 'z'){output = trans[message[k] - 'a'];}
            else if(message[k] >= 'A' && message[k] <= 'Z'){output = trans[message[k] - 'A'] + 'A' - 'a';}
            else if(message[k] == '_'){output = ' ';}
            else {output = message[k];}
            printf("%c", output);
        }
        printf("\n");
    }
    return 0;
}
