#include <iostream>
using namespace std; 

const int var = 1000;

class Set_Class {
	
	int elements[var];
	int cardinality;
	
	public:
		Set_Class(); 																//empty constructor
		Set_Class(int size, int arr[]); 						//constructor from set length and set
		int * getUnion(int size, int arr[]);
};

Set_Class::Set_Class(){
	cardinality = 0; 

	cout << "empty set! \n";
}

Set_Class::Set_Class(int size, int arr[]){
	
	cardinality = size;
	
	for (int i=0; i<=cardinality; i++){
		elements[i] = arr[i]; 
	
	}

	cout << "constructor with size and set\n";
}

int * Set_Class::getUnion(int size, int arr[]){
}

int main() {

	cout << "Hello World!\n";
	
	const int var1 = 5;
	int elems[var1] = {99, 97, 95, 93, 91};

	Set_Class mySet; 
	Set_Class mySet2(var1, elems); 
	
	return 0;

} 
