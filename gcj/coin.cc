#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isNonPrime(long long n, long long & dev){
	for(long long i = 2; i <= sqrt(n); ++i) {
		if (n%i == 0){
			dev = n/i;
			return true;
		}
	}
	return false;
}
void generate(int N, int J){
	int count = 0;
	for(int i= 0; i < pow(2, N-2); ++i) {
		vector<long long> v(9, 0);
		for(int j = 2; j <=10; ++j) {
			long long sum = 0;
			for(int k = 0; k < N-2; ++k) {
				if ((i >> k) & 1){
					sum = pow(j, k+1) + sum;
				}
			}
			sum = pow(j, N-1) + sum+1;
			long long dev;
			if (!isNonPrime(sum, dev)) {
				break;
			} else {
				v[j-2] = dev;
			}
		}
		if (v[8]!=0) {
			cout << 1;
			for(int p = N-3; p>=0; --p) {
				cout << ((i >> p) & 1);
			}
			cout << 1 << " ";
			for(int q = 0; q < 9; ++q) {
				cout << v[q] << " ";
			}
			cout <<endl;
			count++;
			if (count == J) return;
		}
	}
}
int main(){
	int T, N, J;
  	cin >> T >>N >>J;
  	cout << "Case #1:"<<endl;
  	generate(N, J);
}