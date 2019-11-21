#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char * argv[]){

    size_t N; cin >> N;
    size_t numPies = 0, temp = 0, currentPie = 0, currentRack = 0, count = 0;
    vector<size_t> pies,racks;

    for(size_t k = 0; k < N ; k++){
        cin >> numPies;

        for(size_t m = 0; m < numPies ; m++){cin >> temp; pies.push_back(temp);}
        for(size_t m = 0; m < numPies ; m++){cin >> temp; racks.push_back(temp);}
        sort( pies.begin(),  pies.end() ); sort( racks.begin(), racks.end());
         
        count = 0;
        while(pies.size() > 0){
            currentPie  = pies.back(); pies.pop_back();
            currentRack = racks.back();
            if(currentPie <= currentRack){racks.pop_back(); count++;}
        }
        cout << count << endl;
    }
    return 0;
}
