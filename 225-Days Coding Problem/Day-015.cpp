/*
 *  This problem was asked by Facebook.
    Given a stream of elements too large to store in memory, 
    pick a random element from the stream with uniform probability.
 *
 */

/*
 * Here we can choose the first element with 1/1 probability , so 
 * when the next element comes so we have to prove that the element we chosen 
 * is having a probability of 1/(i+1) 
 *
 * When element appears we have only two choices 1. choose this one  2. keep the first 
 *
 * similar thing we gonna do , we will toss a coin (having probability of success 1/2) and if head
 * appears (1) then we replace the element if tail appears (0) in this case then we will keep the element we had.
 *
 *  This is the case since the chance of having
 *  being chosen already but not getting swapped with the ith element is
 *  1 / i * (1 - (1 / (i + 1))) which is 1 / i * i / (i + 1) or 1 / (i + 1)
 */

#include <bits/stdc++.h>
using namespace std;
int main(void){
    srand(time(NULL));
    int current_Element = NULL;
    double probability = 0;
    int n; 
    cin>>n; // number of elements ; don't worry we are not going to use to calculate the probability of selection
    int element_Processed={0};
    while(n--){
        srand(time(NULL));
        int element;
        cin>>element; //
        if(element_Processed == 0){
            element_Processed++;
            current_Element = element;
            probability = 1.0f;
            continue;
        }else if(rand()%2==1)/*case when element should be replaced*/{
            current_Element = element;
        }
        probability = (probability * (1.0f - double(1.0f/double(element_Processed+1.0f))));
        element_Processed++;
    }
    printf("Element %d is chosen with probability %.3f",current_Element , probability);
    return 0;
}
