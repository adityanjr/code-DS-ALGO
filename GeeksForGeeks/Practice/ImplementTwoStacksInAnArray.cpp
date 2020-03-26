/*The structure of the class is
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};
*/


/* The method push to push element into the stack 2 */
void twoStacks :: push1(int x){
    top1++;
    arr[top1] = x;
}
   
/* The method push to push element into the stack 2*/
void twoStacks ::push2(int x){
    top2--;
    arr[top2] = x;
}
   
/* The method pop to pop element from the stack 1 */
int twoStacks ::pop1(){
    if(top1 == -1){
        return -1;
    }
    int ans = arr[top1];
    top1--;
    return ans;
}

/* The method pop to pop element from the stack 2 */
int twoStacks :: pop2(){
    if(top2 == size){
        return -1;
    }
    int ans = arr[top2];
    top2++;
    return ans;
}
