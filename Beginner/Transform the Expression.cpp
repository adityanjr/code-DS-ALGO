#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a, int b){
	if (a==0) return b;
	return gcd(b%a, a);
}

//Returns the precedence of an operator c , returns -1 if the character is not an operator
int getPrecedence(char c) 
{ 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1; 
    else if(c == '(' || c == ')')
        return 0;
    else
        return -1; 
} 

//Function to convert infix expression to postfix expression
string convert(string infix){
    stack<char> s;      //Stack for operators
    string postfix = "(";      //Final postfix string
    s.push('(') ;

    //The expression must be enclosed inside () brackets
    //We added the ( bracket directly into the string and the stack from the beginning and append ) 
    //into the infix expression to denote the end of expression
    infix.push_back(')') ; 

    for(int i=0;i<infix.size();i++) {
        char current = infix[i]; 
        int precedence = getPrecedence(current) ;
  
        if(precedence == -1){
            //Current char is an operand ... simply push into the postfix string and continue 
            postfix = postfix + current ;
        }
        else {
            //Current char is an operator
            //If it is a closing bracket ')' , pop all elements in stack till you get a an open bracket'('
            if(current == ')'){
                char topElement = ' ' ; 
                while(topElement != '('){
                    topElement = s.top() ;
                    if(topElement != '(')
                        postfix = postfix + topElement ;
                    s.pop();
                }
             //   postfix += ')' ;
            }
            else if (current == '('){
                //If current char is an opening bracket , do not pop anything and simply push it into the stack
                s.push(current) ; 
            }
            else {
                //Pop all operators with higher priority
                while(getPrecedence(s.top()) > getPrecedence(current)){
                    char topElement = s.top() ;
                    postfix = postfix + topElement ;
                    s.pop();
                }
                //Then push the current element into the stack
                s.push(current);
            }
        }
    }

    //Remove the extra '(' from postfix added in the beginning 
    postfix.erase(postfix.begin()) ;


    return postfix ; 
}

int main(){
	c_p_c();

	t(x){
		string infixExpression ;
	    cin >> infixExpression ; 

	    string postfix = convert(infixExpression) ;
	    cout << postfix <<endl;
	}

	return 0;
}

---------------------------------------------------------------------

/*
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long t=0;
cin>>t;

while(t--)
    {
    char x,y;
    long long count=0;
    stack <char> st;

    string s="",s1="";
    cin>>s;

    for(long long i=0;i<s.length();i++)
        {
		if(s[i]=='(') {count++;}

        else if(s[i]==')')
            {
			count--;
			x=st.top();
			s1+=x;
			st.pop();
			}

        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
            {
            st.push(s[i]);
            }

        else
            {
		    y=s[i];
		    s1+=y;
		    }
		}
	cout<<s1<<"\n";
    }
return 0;
} */