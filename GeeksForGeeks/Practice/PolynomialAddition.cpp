/* Structure of Node used
struct Node
{
    int coeff;  // coefficient of the polynomial 
    int pow;   // power of the polynomial 
    Node* next;
};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
void addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    string ans = "";
    
    while(p1 || p2){
        int f = -1, s = -1;
        
        if(p1){
            f = p1->pow;
        }
        if(p2){
            s = p2->pow;
        }
        
        if(ans.size() != 0){
            ans = ans + "+ ";
        }
        
        if(f == s){
            ans = ans + to_string(p1->coeff + p2->coeff) + "x^" + to_string(f) + " ";
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(f > s){
            ans = ans + to_string(p1->coeff) + "x^" + to_string(f) + " ";
            p1 = p1->next;
        }
        else{
            ans = ans + to_string(p2->coeff) + "x^" + to_string(s) + " ";
            p2 = p2->next;
        }
    }
    
    cout << ans;
}
