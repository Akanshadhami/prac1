//fibonnaci numbers

#include <bits/stdc++.h>
using namespace std;

//iteratively

void fib(int n){
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	int cnt=2;
	for(int i=2;i<=n-1;i++){
		cnt++;
		v.push_back(v[i-1]+v[i-2]);
	}
	cout<<"Number of iteration = "<<cnt<<endl;
	cout<<"Value = "<<v[n-1]<<endl;
	for(int i=0;i<=n-1;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void fibonacciIterative(int n) {
    int a = 0, b = 1, nextTerm;

    cout << "Fibonacci Series (Iterative): ";
    for (int i = 1; i <= n; ++i) {
        cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    cout << endl;
}

//recursively
int r_cnt=0;

int fib_rec(int n){
	r_cnt++;
	if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main(){
	int n;
	cout<<"enter value = ";
	cin>>n;
	cout<<"********Iterative*********"<<endl;
	fib(n);
	fibonacciIterative(n);
	cout<<"************recursive*******"<<endl;
	cout<<"value = "<<fib_rec(n-1)<<endl;
	cout<<"steps= "<<r_cnt;
	
}