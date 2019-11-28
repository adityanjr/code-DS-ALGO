#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {
    char s[20],c;
    int t,i,j,l;

    scanf("%d",&t);
    getchar();
    while (t--) {
        gets(s);
		l=strlen(s);
        if (l!=5 || s[2]!='-' || !(s[1]>='1' && s[1]<='8') || !(s[4]>='1' && s[4]<='8') || !(s[0]>='a' && s[0]<='h') || !(s[3]>='a' && s[3]<='h')) {
            printf("Error\n");
        }
        else
        {
            i=abs(s[3]-s[0]);
            j=abs(s[4]-s[1]);

            if ((i==1 && j==2)||(j==1 && i==2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}