/*
 *  
    This problem was asked by Facebook.

    Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

    For example, given the string "([])[]({})", you should return true.

    Given the string "([)]" or "((()", you should return false.

 */

class Solution {

    stack<char>temp;

public:

    bool isValid(string s) {

        for(auto&itr:s){

            if(itr == '(' || itr == '[' || itr == '{') {

                temp.push(itr);

            } else{

                if(temp.size() == 0){

                    return false;

                }

                if( itr == ')' ){

                    if( temp.top() != '(' ) {

                        return false;

                    }else{

                        temp.pop();

                    }

                }else if( itr == ']' ){

                    if( temp.top() != '[' ) {

                        return false;

                    }else {

                        temp.pop();

                    }

                }else if( itr == '}' ) {

                    if( temp.top() != '{' ) {

                        return false;

                    }else {

                        temp.pop();

                    }
                }
            }
        }
        return temp.size() == 0;
    }
};

int main( void ) {
    return  0;
}
