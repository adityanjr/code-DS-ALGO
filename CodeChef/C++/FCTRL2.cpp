#include <cstdio>
#include <vector>

std::vector<int> smallFactorial(int n){

    std::vector<int> result(1,1);
    int carry(0);

    while(n > 0){

        for(int k = 0; k < result.size(); k++){
            result[k] = n * result[k] + carry;
            carry = result[k] / 10; 
            result[k] %= 10;
        }
        while(carry > 0){result.push_back(carry % 10); carry /= 10;}

        --n;
    }

    return result;

}


int main(int argc, char * argv[]){

    int numCases(0); scanf("%d", &numCases);
    while(numCases--){
        int input(0); scanf("%d", &input);
        std::vector<int> output = smallFactorial(input);
        for(int k = output.size() - 1; k >= 0; k--){printf("%d", output[k]);} puts("");
    }


    return 0;
}
