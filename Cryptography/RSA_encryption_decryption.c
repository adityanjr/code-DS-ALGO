// this c program follows RSA algorithm
// for encrypting message.
#include<stdio.h>
#include<math.h>
int gcd(int a, int h)
{
int temp;
while(1)
{
temp = a%h;
if(temp==0)
return h;
a = h;
h = temp;
}
}
int gcdExtended(int a, int b, int *x, int *y);
int modInverse(int a, int m)
{
int x, y;
int g = gcdExtended(a, m, &x, &y);
if (g != 1)
printf("Inverse doesn't exist");
else
{
int res = (x%m + m) % m;
return res;
}
}
int gcdExtended(int a, int b, int *x, int *y)
{
if (a == 0)
{
*x = 0, *y = 1;
return b;
}

int x1, y1;
int gcd = gcdExtended(b%a, a, &x1, &y1);
*x = y1 - (b/a) * x1;
*y = x1;
return gcd;
}
int main()
{
int msg=0;
int p = 3;
int q = 11;
int n=p*q;
int count;
int totient = (p-1)*(q-1);
int e=2;
printf("RSA Algorithm Implementation\n");
printf("--------------------------------\n\n");
printf("Prime numbers used are-\np=3 and q=11\n\n");
printf("Enter message: ");
scanf("%d",&msg);
while(e<totient){
count = gcd(e,totient);
if(count==1)
break;
else
e++;
}
int d= modInverse(e,totient);
printf("\nPublic key is {%d,%d}\n",e,n);
printf("Private key is {%d,%d}\n",d,n);
double c = pow(msg,e);
c=fmod(c,n);
double m = pow(c,d);
m=fmod(m,n);
printf("\nEncrypted message (Ciphertext) is- %0.0f\n",c);
printf("Decrypted message (Plaintext) is- %0.0f\n",m);
}