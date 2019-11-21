#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    int t(0); scanf("%d\n", &t);

    while(t--){

        std::string expr(""); getline(std::cin, expr);
        std::vector<char> operators;

        for(int k = 0; k < expr.size(); k++){
            if(expr[k] == '('){continue;}
            else if(expr[k] == '+' || expr[k]  == '-' || expr[k] == '*' || expr[k] == '/' || expr[k] == '^'){operators.push_back(expr[k]);}
            else if(expr[k] == ')'){printf("%c", operators.back()); operators.pop_back();}
            else{printf("%c", expr[k]);}
        }
        puts("");
    }

    return 0;
}
