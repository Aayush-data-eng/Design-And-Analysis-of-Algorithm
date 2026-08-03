#include <iostream>
#include <vector>
using namespace std ;

// Iterative approach
int binarySearchIterative (const vector<int>& arr , int targetValue) {
    int low = 0 , high = arr.size() - 1 ;
    while ( low <= high) {
        int mid = low + (high - low) / 2 ;
        // if target is present at the middle
        if (arr[mid] == targetValue) return mid ;
        // if  taget is greater than mid , ignore the left half
        else if (arr[mid] < targetValue) low = mid + 1 ;
        // if target is smaller than mid , ignore the right half
        else high = mid - 1 ;           
    }
    // target not found
    return -1 ;
}

// Recursive approach
int binarySearchRucursive (const vector <int>& array , int target , int left = 0 , int right = -1) {
    right  = array.size() - 1 ;
    if (right >= left) {

        int middle = left + (right - left) / 2 ;
        if (array[middle] == target) return middle ;

        if (array[middle] > target) return binarySearchRucursive (array , target , left , middle - 1) ;

        return binarySearchRucursive (array , target , middle + 1 , right) ;
    }
    return -1 ;
}

int main () {
    vector<int> dynamicArray ;
    int element ;

    cout << "Enter the Elements in your array: " ;
    while (cin >> element) {
        dynamicArray.push_back(element) ;
    }
    
    int target ;
    cout << "Enter the target value: " ;
    cin.clear() ;
    cin.ignore() ;
    cin >> target ;
    //this is actually slow an alternative is
    // vector<int> dynamicArray = {2,3,4,10,40} ;
    // int target = 10 ;
    int result = binarySearchRucursive(dynamicArray , target) ;
    int result2 = binarySearchIterative(dynamicArray , target) ;
    cout << result << " " << result2 << "\n" ;
    return 1 ;
}