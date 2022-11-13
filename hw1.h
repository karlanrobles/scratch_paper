#ifndef HW1_H
#define HW1_H

#include <iostream>
using namespace std; 

const int var = 1000;

class Set_Class {
	
	
	public: 
		int elements[var];
		int cardinality;
	
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

#endif
