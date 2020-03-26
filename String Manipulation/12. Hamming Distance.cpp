// You are given two strings of equal length, you have to find the Hamming Distance between these string.
// Where the Hamming distance between two strings of equal length is the number of positions at which the 
// corresponding character are different.

// Examples:

// Input : str1[] = "geeksforgeeks", str2[] = "geeksandgeeks"
// Output : 3
// Explanation : The corresponding character mismatch are highlighted.
// "geeksforgeeks" and "geeksandgeeks"

// Input : str1[] = "1011101", str2[] = "1001001"
// Output : 2
// Explanation : The corresponding character mismatch are highlighted.
// "1011101" and "1001001"

// This problem can be solved with a simple approach in which we traverse the strings and count the mismatch 
// at corresponding position. Extended form of this problem is edit distance.

// Algorithm :

// int hammingDist(char str1[], char str2[])
// {
//     int i = 0, count = 0;
//     while(str1[i]!='\0')
//     {
//         if (str1[i] != str2[i])
//             count++;
//         i++;
//     }
//     return count;
// }
// Below is the implementation of two strings.


#include<bits/stdc++.h> 
using namespace std; 
  
// function to calculate Hamming distance 
int hammingDist(char *str1, char *str2) 
{ 
    int i = 0, count = 0; 
    while (str1[i] != '\0') 
    { 
        if (str1[i] != str2[i]) 
            count++; 
        i++; 
    } 
    return count; 
} 
  
// driver code 
int main() 
{ 
    char str1[] = "geekspractice"; 
    char str2[] = "nerdspractise"; 
  
    // function call 
    cout << hammingDist (str1, str2); 
  
    return 0; 
}  

// Output:
// 4

// Time complexity : O(n)
// Note : For Hamming distance of two binary numbers, we can simply return count of set bits in XOR of two numbers.