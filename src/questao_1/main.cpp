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
	bool smaller = true;
	while (smaller) {
		if (*result < avg){
			smaller = true;
			result++;	
		} 
		else smaller = false;
	}

	return result;

}

int main() {
	vector<int> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());

	cout << (*result) << endl;
	
	return 0;
}
