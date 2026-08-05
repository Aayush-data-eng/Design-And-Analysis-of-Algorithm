// Lower bound implementation
// Lower bound returns the index of the first occurence of the given value if there are many occurrences of the given value in the array. If the given value is not present in the array, it returns the index of the first element which is greater than the given value.
int lowerBound (int arr[] , int givenValue , int size) {
    int low = 0 ;
    int high = size - 1 ;
    while (low < high) {
        int mid = low + (high - low) / 2 ;
        if (arr[mid] < givenValue) low = mid + 1 ;
        else high = mid ;
    }
    return low ;
}

// upper bound implementation
// Upper bound returns the index of the first element which is greater than the given value. If the given value is not present in the array, it returns the index of the first element which is greater than the given value.
int upperBound (int arr[] , int givenValue , int size) {
    int low = 0 , high = size - 1 ;
    while (low < high) {
        int mid = low + (high - low) / 2 ;
        if (arr[mid] <= givenValue) low = mid + 1 ;
        else high = mid ;
    }
    return low ;
}