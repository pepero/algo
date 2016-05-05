#include <string>
#include <iostream>
using namespace std;

int fractile(int K, int C, int S){
	for(int i = K; i>=1;--i) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

int main(){
	int T;
  	cin >> T;
  	int i = 0;
  	int K, C, S;
	while (i<T)	{
  		cin >> K>>C>>S;
  		cout << "Case #" << ++i << ": ";
  		fractile(K, C, S); 
	}
}