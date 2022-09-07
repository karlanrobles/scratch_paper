#include <iostream>
using namespace std; 

const int var = 1000;

class Set_Class {
	
	int elements[var];
	int cardinality;
	
	public:
		Set_Class(); 																/* empty constructor											 		*/
		Set_Class(int size, int arr[]); 						/* constructor from set length and set			 	*/
		Set_Class getUnion(Set_Class setB);					/* find the union of the set with a given set */
		Set_Class getIntersection(Set_Class setB);		
		Set_Class getDifference(Set_Class setB);
		bool isSubset(Set_Class setB);
		bool isEmpty();
		bool isElement(int val);
		bool isEqual(Set_Class setB);
		int getCardinality(); 
		void addElement(int val);
		void removeElement(int val);
		void clear();
		int * toArray();
		void print();
};

Set_Class::Set_Class(){
	cardinality = 0; 

	cout << "initalized empty set\n";
}

Set_Class::Set_Class(int size, int arr[]){
	
	cardinality = size;
	
	for (int i=0; i<=size; i++)
		elements[i] = arr[i]; 
	
	cout << "constructor with size " << size << "\n";
}

/*for each element in setA, check if in set B, add non-duplicates to array*/
Set_Class Set_Class::getUnion(Set_Class setB){
	int unionCardinality = 0;
	int unionArray[var];
	int currElem;
	int tempElem;

	Set_Class unionSet(unionCardinality, unionArray);


	for(int i=0; i<cardinality; i++){
		currElem = elements[i];	
		unionSet.addElement(currElem);
	}
	
	for(int i=0; i<setB.cardinality; i++){
		currElem = setB.elements[i];
		unionSet.addElement(currElem);		
	}
	
	return unionSet;
}

/*for each element in setA, check if in set B*/
Set_Class Set_Class::getIntersection(Set_Class setB){
	
	int interCardinality = 0;
	int interArray[var];
	int currElem;
	int tempElem;

	for(int i=0; i<cardinality; i++){
		currElem = elements[i];
		for (int j=0; j<setB.cardinality; j++){
			tempElem = setB.elements[j];
			if (currElem == tempElem){
				interArray[interCardinality] = currElem;
				interCardinality++;
			}
		}
	}
	Set_Class interSet(interCardinality, interArray);
	return interSet;
}


Set_Class Set_Class::getDifference(Set_Class setB){}


bool Set_Class::isSubset(Set_Class setB){
	return true;
}



bool Set_Class::isEmpty(){
	if (cardinality == 0)
		return true;
}




bool Set_Class::isElement(int val){

	for(int i=0; i<cardinality; i++){
		if (elements[i] == val){
			return true;
		}
	}

	return false;
}



bool Set_Class::isEqual(Set_Class setB){} 


int Set_Class::getCardinality(){
	return cardinality;
}

void Set_Class::addElement(int val){
	if (not(this->isElement(val))){
		elements[cardinality] = val;
		cardinality++;
	}
}



/*
	find element index
	shift everything after that index over -1
	cardinality --
*/
void Set_Class::removeElement(int val){
	

}


/*
	set all elements to zero
	cardinality is zero 
*/
void Set_Class::clear(){
	
	for(int i=0; i<cardinality; i++)
		elements[i] = 0; 

	cardinality = 0;
}



int * Set_Class::toArray(){}




void Set_Class::print(){

	cout << "Set: ";

for (int i=0; i<cardinality; i++){
		cout << elements[i] << " ";
	}

cout << "\n";
}

int main() {

	cout << "Hello World!\n";
	
	const int var1 = 5;
	int elems[var1] = {99, 98, 96, 95, 94};
	int elems2[var1] = {99, 97, 95, 93, 91};
	int interCar; 

	Set_Class setA(var1, elems); 
	Set_Class setB(var1, elems2); 
	Set_Class interSet, unionSet, addSet;
	
	cout << "Set A: "; 
	setA.print();
	
	cout << "Set B: ";
	setB.print();
	
	interSet = setA.getIntersection(setB);
	unionSet = setA.getUnion(setB); 

	cout << "Intersection of sets A & B\n";	
	interSet.print();	
	
	cout << "Union of sets A & B\n";
	unionSet.print();
	
	return 0;

} 
