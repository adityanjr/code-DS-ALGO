 #include<bits/stdc++.h>
using namespace std;
#define ll int
#define size_prime 1000001
bool primes[size_prime];
int  sievePrimeFactors[size_prime];
void prime(){
	primes[2]=true;
    for(int i=3;i<=size_prime;i+=2){
        primes[i]=true;
	}

	for(int i=3;i<=size_prime;i++){
		if(primes[i]){
			for(int j=i*i;j<=size_prime;j+=2)
			     primes[j]=false;
		}
	}
}

void prime_factors(){
	sievePrimeFactors[1]=1;
	for(int i=2;i<=size_prime;i++)
	    sievePrimeFactors[i]=i;

	for(int i=4;i<=size_prime;i+=2){
		sievePrimeFactors[i]=2;
	}

	for(int i=3;i<=sqrt(size_prime);i+=2){
              if(sievePrimeFactors[i]==i){
                    for(int j=i*i;j<=size_prime;j+=i)
					   if(sievePrimeFactors[j]==j)
					         sievePrimeFactors[j]=i;
	 		    }
    }
}

int main() {
	ll t,n;
	prime();
	prime_factors();
	cin>>t;
	while(t--){
		cin>>n;
		if(primes[n]){
			cout<<n-1<<endl;
		}
        else{
			unordered_set<int>set;
			int val = n;
			while(n!=1){
				set.insert(sievePrimeFactors[n]);
				n = n/sievePrimeFactors[n];
			}
			 for (auto it=set.begin(); it != set.end(); ++it)
				val = (val * (*it-1))/(*it);
			cout<<val<<endl;
			set.clear();
			}

		}
	return 0;
}
