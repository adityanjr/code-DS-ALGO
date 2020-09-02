/*
 *  This problem was asked by Bloomberg.  
 *  There are N prisoners standing in a circle, waiting to be executed. 
 *  The executions are carried out starting with the kth person, 
 *  and removing every successive kth person going clockwise until there is no one left.  
 *  
 *  Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.
 *  For example, if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.
 *
 *  Bonus: Find an O(log N) solution if k = 2
 *
 *
 *
 *  ping me if you find any error : offamitkumar@gmail.com
 */


//==============Solution===========================
/*
 * Here let's sort out the bonus problem first let killing rate be 2 and people be
 * 1 then answer be 1
 * 2 then answer be 1 
 * 3 then answer be 2
 *
 * We can see that answer for number power of 2^n is just 2*n+l;  where l is 0 for perfect power of 2. 
 * 
 * Now coming the rest of the problem 
 * let our array be [1 , 2 , 3 , 4 , 5, 6 , 7, 8] and killing rate be 3 (consider 0 based indexing)
 * 
 * After First Execution : [4,5,6,7,8,1,2] (array will be shifted by k , So now 4 is our first person from where counting will began for next execution)
 * After Second Execution: [7,8,1,2,4,5] 
 * After Third Execution : [2,4,5,7,8]
 * After Fourth Execution: [7,8,2,4]
 * After Fifth Execution : [4,7,8]
 * After Sixth Execution : [4,7]
 * After Seventh Execution: [7] :: Here we can see that person at index 0 is remaining,, but wait this is final position of the person 
 * where this person is standing when the game began (of course we can't use array n can be 10^18) ;
 * So now think of this as a Recursive solution and try to find out the index of last person 
 * 
 * Index of 7 Before:
 * Seventh Execution happen : (0+3) = 3 ,, wait there were only 2 people present in Sixth Execution so can be person 7 standing at index 3 
 * to take back this in range let's modulo it ,, but by what. Answer is Simple straight forward by current N; 
 *
 * Index of 7 Before:
 * Seventh Execution happen : (0+3)%2 = 1 (as you can see in Sixth Execution 7 is present at index 1)
 * Sixth Execution happen : (1 + 3)%3 = 1 (in Fifth Execution)
 * Fifth Execution happen : (1 + 3)%4 = 0 (in Fourth Execution)
 * Fourth Execution happen: (0 + 3)%5 = 3 (in Third Execution)
 * Third Execution happen : (3 + 3)%6 = 0 (in Second Execution Person 7 is at index 0)
 * Second Execution happen: (0 + 3)%7 = 3 (in First Execution)
 * First Execution happen : (3 + 3)%8 = 6 So person 7 was at index 6 
 *
 *
 * So 6 is our final position if we are starting from index 0 & if we are starting form index 1 then (6+1)th position 
 * or we can say 7th position is our answer :) 
 */

/*===================Solution Links=======================
 * https://www.youtube.com/watch?v=uCsD3ZGzMgE  // watch this for the bonus problem solution 
 * https://www.youtube.com/watch?v=fZ3p2Iw-O2I
 * https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
 * http://giocc.com/a-dynamic-programming-solution-to-the-josephus-problem.html
 *
 * Best : https://medium.com/@rrfd/explaining-the-josephus-algorithm-11d0c02e7212
 */


auto last_Remaining_Persong_Iterative_Solution(int people ,const int &killing_Rate)->int{
    int perfect_position = 0;
    for(int current_number_of_people_remaining =1;current_number_of_people_remaining<=people;++current_number_of_people_remaining){
        // we are backtracking our solution just i had explained above 
        perfect_position = (perfect_position + killing_Rate) % current_number_of_people_remaining;
    }
    return perfect_position+1; // considering it as 1 indexed array 
}

auto last_Remaining_Persong_Recursive_Solution(int people ,const int &killing_Rate)->int{
    return (people>1)?(last_Remaining_Persong_Recursive_Solution(people-1 , killing_Rate)+killing_Rate)%people:0;
}

auto bonus_Solution(int people)->int{
    // get most significant bit
    int msb = 1;
    while(msb<people){
        msb<<=1;// shifting the bit
    }
    return 2*(people)-msb+1;
}

#include <bits/stdc++.h>
using namespace std;
int main(void){
    int people , killing_Rate;
    cin >> people >> killing_Rate;
    if(killing_Rate==2){
        cout<<"Last Remaining Person : "<<bonus_Solution(people)<<endl;
    }else {
        cout<<"Last Remaining Person : "<<last_Remaining_Persong_Iterative_Solution(people , killing_Rate)<<endl;
        cout<<"Last Remaining Person : "<<last_Remaining_Persong_Recursive_Solution(people , killing_Rate)+1<<endl;
    }
    return 0;
}
