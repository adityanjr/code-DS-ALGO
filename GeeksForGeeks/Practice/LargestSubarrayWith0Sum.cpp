/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  map<int, vector<int> > m;
  
  int sum = 0, ans = 0;
  
  for(int i = 0; i < n; i++){
      sum += A[i];
      m[sum].push_back(i);
  }
  
  map<int, vector<int> > :: iterator it = m.begin();
  
  while(it != m.end()){
      if(it->first == 0){
          ans = max(ans, (it->second)[(it->second).size()-1]+1);
      }
      else{
          ans = max(ans, (it->second)[(it->second).size()-1]-(it->second)[0]);
      }
      
      it++;
  }
  
  return ans;
}
