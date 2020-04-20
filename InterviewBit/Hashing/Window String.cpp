//  https://www.interviewbit.com/problems/window-string/

string Solution::minWindow(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    int hasfound[256] = {0};
    int shouldfind[256] = {0};
    
    for(int i=0;i<m;i++)
        shouldfind[B[i]]++;
    
    int ml = INT_MAX, left=0, right=0;
    int start=0, end=0, cnt=0;
    
    for(;end<n;end++) {
        if(shouldfind[A[end]]==0)
            continue;
        hasfound[A[end]]++;
        
        if(shouldfind[A[end]]>=hasfound[A[end]])
            cnt++;
        
        if(cnt==m) {
            while(shouldfind[A[start]]==0 || hasfound[A[start]]>shouldfind[A[start]]) {
                if(hasfound[A[start]]>shouldfind[A[start]])
                    hasfound[A[start]]--;
                start++;
            }
            
            if(ml > end-start+1) {
                ml = end-start+1;
                left = start;
                right = end;
            }
            
        }
    }
    return (ml==INT_MAX)?"":A.substr(left, ml);
}

