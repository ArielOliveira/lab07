#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last) {
	int avg = 0, count = 0;
	for (InputIterator it = first; it != last; it++) {
		avg += *it;
		count++;
	}
	avg /= 6;
	InputIterator result = first;
	int smaller = 1;
	while (smaller) {
		if (*result < avg){
			smaller = 1;
			result++;	
		} 
		else smaller = 0;
	}

	return result;

}

int main() {
	vector<int> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());

	cout << (*result) << endl;
	
	return 0;
}
