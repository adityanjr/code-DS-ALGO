//https://codefights.com/interview-practice/task/AaWaYxi8gjtbqgp2M/description

// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

//------------------------------------ ITERATIVE SOLUTION ----------------------------------------------//

#define nodeptr Tree<int>*
Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
  if(preorder.size()==0)return nullptr;
  stack<nodeptr> stk;
  int preptr=0;
  int inptr=0;
  nodeptr root;
  nodeptr cur=new Tree<int>(preorder[0]);
  stk.push(cur);
  root=cur;
  preptr++;
  bool isRight=false;
  while(inptr<inorder.size()){
    if(stk.size()==0 or inorder[inptr]!=stk.top()->value){
      if(isRight){
        cur->right = new Tree<int>(preorder[preptr]);
        cur=cur->right;
        isRight=false;
      }else{
        cur->left = new Tree<int>(preorder[preptr]);
        cur=cur->left;
      }
      preptr++;
      stk.push(cur);
    }else{
      isRight=true;
      cur=stk.top();
      stk.pop();
      inptr++;
    }
  }
  return root;
}

//------------------------------------------- RECURSI1VE SOLUTION -------------------------------------//

// #define nodeptr Tree<int>*
// int indx=0;
// nodeptr helper(vector<int> &inorder,int lf,int rt,vector<int> &preorder){
//   int id = -1;
//   for(int i=lf;i<=rt;i++)
//     if(inorder[i]==preorder[indx]){
//       id=i;
//       break;
//     }

//   if(id==-1)return nullptr;
//   nodeptr root = new Tree<int>(preorder[indx]);
//   indx++;
//   root->left = helper(inorder,lf,id-1,preorder);
//   root->right = helper(inorder,id+1,rt,preorder);
//   return root;
// }

// Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
//   return helper(inorder,0,inorder.size()-1,preorder);
// }
