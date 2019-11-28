#include <bits/stdc++.h>
using namespace std;
	
int main() {
	int n1, n2, n3, temp;
	scanf("%d %d %d",&n1,&n2,&n3);

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> result;
	set<int> s;

	for(int i = 0; i < n1; i ++) {
		cin >> temp;
		s.insert(temp);
		v1.push_back(temp);
	}
	sort(v1.begin(), v1.end());

	for(int i = 0; i < n2; i ++) {
		cin >> temp;
		s.insert(temp);
		v2.push_back(temp);
	}
	sort(v2.begin(), v2.end());

	for(int i = 0; i < n3; i ++) {
		cin >> temp;
		s.insert(temp);
		v3.push_back(temp);
	}
	sort(v3.begin(), v3.end());

	temp = 0;
	for (set<int>::iterator it=s.begin(); it!=s.end(); ++it) {
		int count = 0;
		if(binary_search(v1.begin(), v1.end(), *it))
			count++;
		if(binary_search(v2.begin(), v2.end(), *it))
			count++;
		if(binary_search(v3.begin(), v3.end(), *it))
			count++;

		if(count >= 2) {
			temp++;
			result.push_back(*it);
		}
	}

	cout << result.size() << "\n";
	for(vector<int>::iterator it=result.begin(); it!=result.end(); ++it)
		cout << *it << "\n";
    
	return 0;
}