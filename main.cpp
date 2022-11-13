#include <iostream>
#include "hw1.h"
using namespace std; 

int main() {

	const int var1 = 5;
	const int var2 = 3;
	const int var3 = 0;
	
	int* toArr;
	
	int element = 99;
	int elems[var1] = {99, 98, 96, 95, 94};
	int elems2[var1] = {99, 97, 95, 93, 91};
	int elems3[var2] = {96, 95, 94};
	int elems4[var3] = {};
	int elems5[var2] = {95,94,96};

	// a) different constructors to initialize the set
	Set_Class setA(var1, elems); 									
	Set_Class setB(var1, elems2); 
	Set_Class setC(var2, elems3);
	Set_Class setD(var2, elems5);
	Set_Class interSet, unionSet, diffSet, emptySet, addSet; 
	
	


	// h) print method to print elements of the set
	cout << "Set A: "; 
	setA.print();																
	
	cout << "Set B: ";
	setB.print();
	
	cout << "Set C: ";
	setC.print();

	cout << "Set D: ";
	setC.print();


	cout << "\n\n";

	
	// b) find the union of the set with a given set
	cout << "Union of sets A & B\n";
	unionSet = setA.getUnion(setB); 
	unionSet.print();
	
	cout <<"\n\n";


	// c) find the intersection of the set with a given set
	cout << "Intersection of sets A & B\n";		
	interSet = setA.getIntersection(setB);				
	interSet.print();	
 
 	cout << "\n\n";


	// d) find the difference of the set with a given set 
	cout << "Difference of set A and B\n";
	diffSet = setA.getDifference(setB);
	diffSet.print();

	cout << "\n\n";

	// e) check whether the set is subset of another set
	bool setCSubset, setBSubset;
	setCSubset = setA.isSubset(setC);
	setBSubset = setA.isSubset(setB);

	cout << "Check if set C is subset of set A\n";
	if (setCSubset)
		cout << "Set C is a subset of Set A\n";
	else
		cout << "Not a subset\n";
	cout << "Check if set B is subset of set A\n";	
	if (setBSubset)
		cout << "Set B is a subset of Set B\n";

	cout << "\n\n";

	// f) isEmpty method returns true if the set is empty
	cout << "Given an empty set, isEmpty method returns: ";
	cout << emptySet.isEmpty() << "\n\n";
	

	// g) isElement takes an element and checks if it's in the set
	cout << "Given an element, isElement checks if " << element << " is in the set A ";
	setA.print();  
	cout << "and returns: ";
	cout << setA.isElement(element) << "\n\n"; 
	


	// h) isEqual checks if the set is equal to a given set 
	cout << "Check if set A is equal to set D \n"; 
	cout << setA.isEqual(setD) << "\n\n";



	// i) getCardinality returns the cardinality of the set
	cout << "Set A cardinality: " << setA.getCardinality() << "\n" ;
	cout << "Set B cardinality: " << setB.getCardinality() << "\n" ;
	cout << "Set C cardinality: " << setC.getCardinality() << "\n" ;
	cout << "Set D cardinality: " << setD.getCardinality() << "\n" ;

	

	// j) addElement adds element to set, checks that element is not already in set
	cout << "Set A: ";
	setA.print(); 
	setA.addElement(element);
	cout << "Added an element 99, updated set A: ";
	setA.print();
	cout << "\n\n";
	
	
	cout << "Set C: ";
	setC.print();
	setC.addElement(element); 
	cout << "Added an element 99, updated set C: ";
	setC.print();
	cout << "\n\n";

	// k) removeElement from the set
	cout << "Removed element from set A: ";
	setA.removeElement(element);
	setA.print(); 
	cout << "\n\n";

	cout << "Removed element from set C: ";
	setC.removeElement(element);
	setC.print();
	cout << "\n\n";
	

	// l) clear removes all elements from the set
	cout << "Cleared all elements from set C: ";
	setC.clear();
	setC.print();
	cout << "\n\n";


	// m) toArray
	cout << "Converted set class to array, set A in array form: ";
	toArr = setA.toArray(); 
	for (int i=0; i<setA.cardinality; i++){
		cout << toArr[i] << " "; 
	}
	cout << "\n\n"; 

	// n) print method (used above and throughout


	return 0;

} 
