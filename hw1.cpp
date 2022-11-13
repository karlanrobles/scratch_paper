#include <iostream>
#include "hw1.h"
using namespace std; 

//const int var = 1000;


/*initialize empty set*/
Set_Class::Set_Class(){
	cardinality = 0; 
}


/*initialize set given size and elements*/
Set_Class::Set_Class(int size, int arr[]){
	
	cardinality = size;
	
	for (int i=0; i<size; i++)
		elements[i] = arr[i]; 
	
}



/*add each element in setA to union set 
	check if setB elements are in union set
	add non-duplicates elements to union set*/
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



/*for each element in setA, check if in set B
	insert matching elements to intersection array
	create intersection set
*/
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



/*remove matching elements
	for all elements in setA, 
		if not match - insert in difference
		if matche - do not insert
*/
Set_Class Set_Class::getDifference(Set_Class setB){

	int currElement;

	int diffCardinality = 0;
	int diffArray[var];
	Set_Class diffSet(diffCardinality, diffArray);

	for (int i=0; i<setB.cardinality; i++){
		currElement = setB.elements[i];
		if (not(this->isElement(currElement)))
			diffSet.addElement(currElement);
	}
	return diffSet;
}

/*
	if 
		for all items in setB 
			in setA
*/
bool Set_Class::isSubset(Set_Class setB){
	
	int currElement;
	bool isSub = false;

	for (int i=0; i<setB.cardinality; i++){
		currElement = setB.elements[i];
		if (not(this->isElement(currElement))) 
			return isSub;
	}

	return true;
}


bool Set_Class::isEmpty(){
	if (cardinality == 0)
		return true;
}


bool Set_Class::isElement(int val){

	for(int i=0; i<cardinality; i++){
		if (this->elements[i] == val){
			return true;
		}
	}

	return false;
}



bool Set_Class::isEqual(Set_Class setB){
	if (setB.isSubset(*this) and this->isSubset(setB))
		return true;
} 


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
	find element index by looping through elements
	shift everything after that index over -1
	cardinality --
*/
void Set_Class::removeElement(int val){
	
	int currElement;

	int valIndex; 

	if (this->isElement(val)){	

		for (int i=0; i<cardinality; i++){
			if (elements[i] == val){
				valIndex = i;
			}
		}

		for (int i=valIndex; i<cardinality; i++){
			elements[i] = elements[i+1];
		}
	}

	cardinality--;
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



int * Set_Class::toArray(){
	return elements;

}




void Set_Class::print(){

	cout << "[ ";

	for (int i=0; i<cardinality; i++){
		cout << elements[i] << " ";
	}

	cout << "]\n";
}

