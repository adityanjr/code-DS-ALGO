#include <iostream>
using namespace std;

int main(){

    int numCases = 0, numNodes = 0, nodeID = 0, sumChildren = 0, root = 0;
    scanf("%d\n",&numCases);

    do{ scanf("%d\n",&numNodes);
        root = 0;
        do{ scanf("%d %d\n", &nodeID, &sumChildren);
            root += nodeID - sumChildren;
        }while(--numNodes);
        printf("%d\n",root);
    }while(--numCases);
    return 0;
}
