// # Armstrong number

// Given a number x, determine whether the given number is Armstrong number or not. A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if :

// >**abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ....**

// ## Example:

// Input : 1634 <br/>
// Output : The number is armstrong <br/>
// 1<sup>4</sup> + 6<sup>4</sup> + 3<sup>4</sup> + 4<sup>4</sup> = 1634

#include<stdio.h>
#include<math.h>

int main(void)
{
	int n,r,a=0,t,c=0,z;
	printf("Enter a number: ");
	scanf("%d",&n);
	t=n; z=n;
	while(z>0)
    {
       z=z/10;
       c++;
    }
	while(n>0)
    {
        r=n%10;
        a=a+pow(r,c);
        n=n/10;
    }
    if(a==t)
        printf("\nThe number is armstrong\n");
    else printf("\nThe number is not armstrong\n");
    return 0;
}
