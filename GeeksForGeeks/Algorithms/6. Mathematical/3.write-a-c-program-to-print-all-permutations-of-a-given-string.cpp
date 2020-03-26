// http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string

#include <iostream>
#include <cstring>
using namespace std;

void permute(string str, int n, string res){
    if(n == 0){
        cout<<res<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        string a, c;
        a = str.substr(0, i);
        char b = str[i];
        c = str.substr(i+1);
        permute(a+c, n-1, res+b);
    }

}

/*BackTrack*/
void _permute(string str, int low, int high){
    if(low == high){
        cout<<str<<"\n";
        return;
    }
    for(int i=low; i<=high; i++){
        swap(str[i], str[low]);
        _permute(str, low+1, high);
        swap(str[i], str[low]);   //BackTrack
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    //permute(string(str), n, "");
    _permute(string(str), 0, n-1);
	return 0;
}


