#include <iostream>

using namespace std;

typedef struct petrol_stations {
    int petrol;
    int dist;
}petrol_pumps;

int find_circ_tour(petrol_pumps* s, int n) {

    int p = 0,start=0,end=1;
    p += (s[start].petrol - s[start].dist);
    while(start !=end) {

        ///if(p<0) { p = 0; start = end; }

        /// POP the queue if sum is negative...
        while (p < 0 && start!=end) {

            p -= (s[start].petrol - s[start].dist);
            start = (start + 1) % n;

            if(start == 0) {
                cout << "Tour not possible" << endl;
                return -1;
            }
        }

        /// PUSH the queue if sum is positive...
        p += (s[end].petrol - s[end].dist);
        end = (end + 1) % n;
    }

    cout << "Tour is complete..petrol left: " << p << endl;
    return start;

}

int main() {

    int N,p,d;
    cout << "How many <petrol,dist> pairs do you want to enter?" << endl;
    cin >> N;

    petrol_pumps *stations = new petrol_pumps[N];
    for(int i=0;i<N;i++) {
        cin >> p >> d;
        stations[i].petrol = p;
        stations[i].dist = d;
    }

    int init_loc = find_circ_tour(stations,N);
    cout << "Start your tour at petrol pump (i+1): ";
    (init_loc==-1) ? cout << "-1" << endl : cout << init_loc+1 << endl;

}
