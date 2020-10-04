#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

main()
{
    int i,j,k = 0,n;
    char  a[100],b[100];
    cout<<"ENTER THE WORD\n";
    gets(a);
    cout<<"ENTER ANOTHER WORD\n";
    gets(b);
    if(strlen(a)!=strlen(b))
    {
        cout<<"THESE ARE NOT ANAGRAMS";
    }
    else
    {
        n = strlen(a);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i]==b[j])
                {
                    b[j] = 48;
                    break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(b[i]==48)
            {
                k++;
            }
        }
        if(k==n)
        {
            cout<<"THESE ARE ANAGRAMS\n";
        }
        else
        {
            cout<<"THESE ARE NOT ANAGRAMS\n";
        }
    }

}
