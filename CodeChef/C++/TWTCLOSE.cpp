#include <iostream>
using namespace std;

int main(){

    size_t numTweets, numClicks;
    scanf("%zd %zd\n", &numTweets , &numClicks);
    
    bool *state = new bool[numTweets+1];
    for(size_t k = 1; k <= numTweets; k++){state[k] = 0;}

    size_t clickedTweet = 0, openTweets = 0;
    char action[10];

    for(size_t k = 0; k < numClicks; k++){
        scanf("%s",action);
        if(action[2]=='I'){
            scanf("%zd\n",&clickedTweet);
            state[clickedTweet] = 1 - state[clickedTweet];
            openTweets += 2*state[clickedTweet] -1;
        }

        else if(action[2] == 'O'){
            for(size_t k = 1; k <= numTweets; k++){state[k] = 0;};
            openTweets = 0;
        }

        printf("%zd\n",openTweets);
    }

    return 0;
}
