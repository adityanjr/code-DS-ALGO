#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        std::string x, y; std::cin >> x >> y;
        std::string z(x);
        for(int p = 0; p < z.size(); p++){
            if(x[p] == 'B' && y[p] == 'B'){z[p] = 'W';}
            else if(x[p] == 'W' && y[p] == 'W'){z[p] = 'B';}
            else{z[p] = 'B';}
        }

        std::cout << z << std::endl;
    }

    return 0;
}
