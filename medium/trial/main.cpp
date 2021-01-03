#include<bits/stdc++.h>
using namespace std;

void debug_set(set<int> & s){
	for (int i: s)
		cout << i << ' ';
	
	cout << '\n';
}


int main(){

	set<int> s;
	for (int i= 0; i <= 10; i++)
		s.insert(i);
	auto endd = s.end();
	endd++;
	for (auto it = s.begin(); it != s.end() && it!=endd;){
		auto x = s.find(*it);
		it++,it++;
		s.erase(x);
		debug_set(s);
	}

	return 0;
}
