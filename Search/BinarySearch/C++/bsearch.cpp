#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> myarray;


bool binary_search(int number) {
    int higher = myarray.size();
    int lower = 0;
    int mid;

    while(lower <= higher) {
        mid = (lower + (higher - lower)) / 2;
        if (number == myarray[mid])
        {
            std::cout << "found at pos: " << mid + 1 << std::endl;
            std::cout << myarray[mid] << std::endl;
            return true;
        }
        else if (number > myarray[mid])
            lower = mid;
        else if (number < myarray[mid])
            higher = mid;

        if (higher - lower == 1)
            return false;
    }
}


int main(int argc, char const *argv[])
{

    std::string z;
    while(true)
    {
        std::cin>>z;
        if (is_digits(z))
        {
            int input = stoi(z);
            myarray.push_back(input);
        }
        else
            break;
    }



    std::cout<<"enter number you want to search"<<std::endl;
    int k;
    std::cin>>k;
    bool found = binary_search(k);
    if(found == false)
        std::cout<<"couldn't find number"<<std::endl;
    return 0;
}
