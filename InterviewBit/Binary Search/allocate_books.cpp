//  https://www.interviewbit.com/problems/allocate-books/

bool isValidConfig(vector<int> &A, int B, int ans) {
    
    int students = 1;
    int current_pages = 0;
    int n = A.size();
    
    for(int i=0;i<n;i++) {
        if(current_pages+A[i]>ans) {
            current_pages = A[i];
            students++;
            if(students>B)
                return false;
        }
        else {
            current_pages += A[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    
    int total_pages = 0;
    int s = 0, e = 0;
    int n = A.size();
    
    if(B>n)
        return -1;
    
    for(int i=0;i<n;i++) {
        total_pages += A[i];
        s = max(s, A[i]);
    }
    e = total_pages;
    
    int final_ans = -1;
    
    while(s<=e) {
        
        int mid = (s+e)/2;
        
        if(isValidConfig(A, B, mid)) {
            final_ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return final_ans;
}

