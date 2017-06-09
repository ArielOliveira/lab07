#include <iostream>
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <vector>
using std::vector;


template<typename TContainer>
void print_elements(const TContainer& collection, const char* label="", const char separator=' ') {
	cout << label << " ";
	for (typename TContainer::const_iterator it = collection.begin(); it !=collection.end(); it++) {
		cout << *it;
		if (*it != *collection.end()) {
			cout << separator;
		}
	}
	cout << endl;
}

int main() {

	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);
	print_elements(numeros, "Set: ");
	print_elements(numeros, "CSV Set: ", ';');
	
}
