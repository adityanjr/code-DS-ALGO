#include <iostream>
using namespace std;

int main(int argc, char* argv[]){

    const size_t maxPrice = 2048;
    size_t divisor, menuItems, total;
    size_t N; scanf("%zd",&N);

    for(size_t k = 0; k < N ; k++){
        size_t number; scanf("%zd",&number);

        divisor = maxPrice;
        total = 0;

        while(divisor > 0){
            menuItems = number / divisor ;
            total += menuItems;
            number = number - (menuItems * divisor) ;
            if(number == 0){break;}
            divisor /= 2;
        }
        printf("%zd\n",total);
    }
    return 0;
}
