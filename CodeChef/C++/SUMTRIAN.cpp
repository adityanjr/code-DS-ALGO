#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

    size_t N;cin >> N;
    size_t arraySize;

    for(size_t k = 0; k < N ; k++){
        cin >> arraySize;
        const int numLines = arraySize;
        int matrix[numLines][numLines];
        int inputNumber = 0;

        cin >> matrix[0][0];
        for(int row = 1; row < numLines ; row++){
            cin >> inputNumber; matrix[row][0] = matrix[row-1][0] + inputNumber; 
            for(int col = 1; col < row  ; col++){
                cin >> inputNumber;matrix[row][col] = max(matrix[row-1][col-1],matrix[row-1][col]) + inputNumber;
            }
            cin >> inputNumber; matrix[row][row] = matrix[row-1][row-1] + inputNumber;
        }
        
        int currentMax = -1;
        for(int col = 0; col < numLines; col++){currentMax = max(currentMax,matrix[numLines-1][col]);}
        cout << currentMax << endl;
    }

    return 0;
}
