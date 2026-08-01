#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(const vector<int>& arr , int targetValue) {
    for(int i = 0 ; i < arr.size() ; i++) {
        if(arr[i] == targetValue) {
            return i;
        }
    }
    return -1;
}

int main () {
    vector <int> array;
    int terms;
    cout << "Enter the number of terms in the array: ";
    cin >> terms ;
    array.resize(terms) ;
    cout << "Enter the values in the array: " ;
    for (int i = 0 ; i < terms ; i++) {
        cin >> array[i] ;
    }

    // The input of the array through the loop can also be done without initialising the array:
    /*
    vector <int> array ;
    cout << "Enter the values to be added in the array(type any letter or symbol other than any numeric value to stop the iteration): " ;
    int number ;
    while (cin >> number) {
        array.push_back(number) ;}

    This is how to grow our vector based aray dynamically without knowing the number of terms in advance. The loop will continue until a non-numeric value is entered, at which point the input will stop and the program will proceed to search for the target value.
    */

    int target ;
    cout << "Give the value to be searched: " ;
    cin >> target ;

    int result = LinearSearch(array , target) ;
    if (result != -1) {
        cout << "The value provided that is, " << target << " is found at index: " << result << " and at position: " << result + 1 << "\n" ;         
    }
    else cout << "The value provisded , that is, " << target << " is not found in the array\n" ;
    return 1 ;
}