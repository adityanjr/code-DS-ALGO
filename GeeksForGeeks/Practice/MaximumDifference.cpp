/*You are required to complete this method */
int findMaxDiff(int A[], int n)
{
  //Your code here
  vector<int> left(n, 0);
  vector<int> right(n, 0);
  
  stack<int> st;
  stack<int> stt;
  
  for(int i = 0; i < n; i++){
      if(st.empty()){
          st.push(i);
      }
      else{
          while(!st.empty() && A[st.top()] >= A[i]){
              st.pop();
          }
          if(!st.empty()){
              left[i] = A[st.top()];
          }
          st.push(i);
      }
  }
  
  for(int i = n-1; i >= 0; i--){
      if(stt.empty()){
          stt.push(i);
      }
      else{
          while(!stt.empty() && A[stt.top()] >= A[i]){
              stt.pop();
          }
          if(!stt.empty()){
              right[i] = A[stt.top()];
          }
          stt.push(i);
      }
  }
  
  int ans = 0;
  
//   for(int i = 0; i < n; i++){
//       cout << left[i] << " ";
//   }
  
//   cout << endl;
  
//   for(int i = 0; i < n; i++){
//       cout << right[i] << " ";
//   }
  
//   cout << endl;
  
  for(int i = 0; i < n; i++){
      ans = max(ans, abs(left[i] - right[i]));
  }
  
  return ans;
}
