// https://codefights.com/interview-practice/task/RvDFbsNC3Xn7pnQfH/description

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
#define nodeptr ListNode<int>*
nodeptr reverseList(nodeptr head){
    if(!head)return head;
    nodeptr prev=NULL;
    nodeptr cur=head;
    nodeptr nex=cur->next;
    while(cur){
        cur->next=prev;
        prev=cur;
        cur=nex;
        if(nex)nex=nex->next;
    }
    return prev;
}
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    nodeptr head1=reverseList(a);
    nodeptr head2=reverseList(b);
    
    nodeptr head3=NULL;
    nodeptr temp=head3;
    int carry=0;
    while(head1!=NULL and head2!=NULL){
        int num1 = head1->value;
        int num2 = head2->value;
        int res=0;
        string str="";
        for(int i=1;i<=4;i++){
            int sum=(num1%10 + num2%10 + carry)%10;
            carry = (num1%10 + num2%10 + carry)/10;
            str+=(char)(sum+'0');
            num1/=10;
            num2/=10;
        }
        reverse(str.begin(),str.end());
        int st=0;
        int toput=0;
        for(st=0;st<4;st++)if(str[st]!='0')break;
        if(st==4)toput=0;
        else {
            for(int i=st;i<4;i++){
                toput=toput*10+(str[i]-'0');
            }
            
        }
        nodeptr nod = new ListNode<int>(toput);
        if(head3==NULL){
            head3=nod;
            temp=nod;
        }else{
            temp->next=nod;
            temp=nod;
        }
        head1=head1->next;
        head2=head2->next;
    }
    
    while(head1!=NULL){
        int num1 = head1->value;
        int res=0;
        string str="";
        for(int i=1;i<=4;i++){
            int sum=(num1%10 + carry)%10;
            carry = (num1%10 + carry)/10;
            str+=(char)(sum+'0');
            num1/=10;
        }
        reverse(str.begin(),str.end());
        int st=0;
        int toput=0;
        for(st=0;st<4;st++)if(str[st]!='0')break;
        if(st==4)toput=0;
        else {
            for(int i=st;i<4;i++){
                toput=toput*10+(str[i]-'0');
            }
            
        }
        nodeptr nod = new ListNode<int>(toput);
        if(head3==NULL){
            head3=nod;
            temp=nod;
        }else{
            temp->next=nod;
            temp=nod;
        }
        head1=head1->next;
    }
    
    while(head2!=NULL){
        int num2 = head2->value;
        int res=0;
        string str="";
        for(int i=1;i<=4;i++){
            int sum=(num2%10 + carry)%10;
            carry = (num2%10 + carry)/10;
            str+=(char)(sum+'0');
            num2/=10;
        }
        reverse(str.begin(),str.end());
        int st=0;
        int toput=0;
        for(st=0;st<4;st++)if(str[st]!='0')break;
        if(st==4)toput=0;
        else {
            for(int i=st;i<4;i++){
                toput=toput*10+(str[i]-'0');
            }
            
        }
        nodeptr nod = new ListNode<int>(toput);
        if(head3==NULL){
            head3=nod;
            temp=nod;
        }else{
            temp->next=nod;
            temp=nod;
        }
        head2=head2->next;
    }
    
    if(carry>0){
        nodeptr nod = new ListNode<int>(carry);
        if(head3==NULL){
            head3=nod;
            temp=nod;
        }else{
            temp->next=nod;
            temp=nod;
        }
    }
    head3=reverseList(head3);
    return head3;
   
}
