#include <iostream>
#include <string>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    const std::string a = "010"; 
    const std::string b = "101"; 

    while(t--){
        std::string s; std::cin >> s;
        std::cout << ((s.find(a) == std::string::npos && s.find(b) == std::string::npos) ? "Bad" : "Good") << std::endl;
    }

    return 0;
}
