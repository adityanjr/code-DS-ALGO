/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


void topSort(vector<int> graph[], int curr, map<int, bool>& visited, stack<int>& ans){
    if(visited.find(curr) != visited.end()){
        return;
    }
    
    for(int i = 0; i < graph[curr].size(); i++){
        if(visited.find(graph[curr][i]) == visited.end()){
            topSort(graph, graph[curr][i], visited, ans);
        }
    }
    
    visited[curr] = true;
    ans.push(curr);
}

/* You need to complete this function */
int * topoSort(vector<int> graph[], int N)
{
   // Your code here
   map<int, bool> visited;
   stack<int> st;
   
   for(int i = 0; i < N; i++){
       topSort(graph, i, visited, st);
   }
   
   int *ans = new int[N], i = 0;
   
   while(!st.empty()){
       ans[i] = st.top();
       st.pop();
       i++;
   }
   
   return ans;
}
