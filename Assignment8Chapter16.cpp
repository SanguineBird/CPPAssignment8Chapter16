/*
Meghan Moore
April 4, 2015
CIT 245 - Data Structures and Programming C++
Assignment 8 - Chapter 15
Purpose: Template a binary search function. Prove that it works with at least 2 types of data.
*/

#include <iostream> //cin, cout, cerr, endl
#include <cstdlib> //system
using namespace std;

//Searches for a single value in an array. (is recurrent)
//Precondition: Array elements must be sorted in ascending order,
//and T type must work with comparison operators (==, <, >).
template<class T>
void binarySearch(T searchValue, T array[], int midPoint, int arraySize){
  if(array[midpoint] == searchValue)
    cout << searchValue << " is at index " << midPoint << endl;
  
  else if(searchValue < array[midPoint]){
    if((midPoint/2) >= 0)
      binarySearch(searchValue, (midPoint/2), array[], midPoint);
    else if midpoint > 0
        binarySearch(searchValue, (midpoint-1), array[], midPoint);
    else
      cout << searchValue << " is not in the array.\n";
  }
  
  else if(searchValue > array[midPoint]){
    if((midPoint/2) + midPoint <= arraySize)
      binarySearch(searchValue, (midPoint/2 + midPoint), array[], arraySize);
    else if(midPoint < arraySize)
      binarySearch(searchValue, (midPoint + 1), array[], arraySize);
    else
      cout << searchValue << " is not in the array.\n";
  }
  
  else
    cout << searchValue << " is not in the array.\n";
}//end binarySearch

int main(){
  int numSize = 11;
  int i; //counter
  
  int numbers[numSize] = {0, 1, 1, 2, 3, 5, 6, 13, 21, 32, 55};
  cout << "Integeter test array contains:\n";
  for(i = 0; i < numSize; i++){
    cout << numbers[i] << " ";
  }
  cout << endl;
  
  for(i = -1; i <= 7; i++){
    binarySearch(i, numbers, (numSize/2), numSize);
  }
  cout << endl;
  
  int stringSize = 4
  string anatomy[stringSize] = {"head", "knees", "shoulders", "toes"};
  cout << "String test array contains:\n";
  for(i = 0; i < stringSize; i++){
    cout << anatomy[i] << " ";
  }
  cout << endl;
  
  binarySearch("elbows", anatomy, (stringSize/2), stringSize);
  binarySearch("knees", anatomy, (stringSize/2), stringSize);
  
  system("pause");
  return 0;
}//end main
