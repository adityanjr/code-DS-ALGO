#include <iostream>
using namespace std;

int main(){

    const int alphabetSize = 26;
    string names;
    long letterCount[alphabetSize] = {0};

    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        bool substring = 1;
        for(int k = 0; k < alphabetSize; k++){letterCount[k]=0;}

        getline(cin, names);
        for(size_t k = 0; k < names.size(); k++){
            char currentLetter = names[k];
            if(currentLetter >= 'a' && currentLetter <= 'z'){letterCount[currentLetter - 'a']++;}
        }

        int numChildren; scanf("%d\n",&numChildren);
        while(numChildren--){
            getline(cin,names);
            for(size_t k = 0; k < names.size(); k++){
                char currentLetter = names[k];
                letterCount[currentLetter - 'a']--;
                if(letterCount[currentLetter - 'a'] < 0){substring = 0; break;}
            }
            if(!substring){break;}
        }

        puts(substring ? "YES" : "NO");
    }

    return 0;
}
