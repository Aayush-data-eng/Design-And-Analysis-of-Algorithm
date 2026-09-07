#include <iostream>
#include <ctime>

using namespace std;

void insertion_sort(float bucket[], int size)
{
    for (int i = 1; i < size; i++)
    {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

// Bucket Sort
void bucket_sort(float arr[], int n)
{
    // Create 20 buckets
    float buckets[20][20];
    int bucketSize[20] = {0};

    for (int i = 0; i < n; i++)
    {
        int bi = int(n * arr[i]);

        buckets[bi][bucketSize[bi]] = arr[i];
        bucketSize[bi]++;
    }

    for (int i = 0; i < n; i++)
    {
        insertion_sort(buckets[i], bucketSize[i]);
    }
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucketSize[i]; j++)
        {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main()
{
    float arr[20] = {
        0.78, 0.17, 0.39, 0.26, 0.72,
        0.94, 0.21, 0.12, 0.23, 0.68,
        0.55, 0.31, 0.89, 0.45, 0.63,
        0.08, 0.97, 0.36, 0.51, 0.15
    };

    int n = 20;

    cout << "Original Array:" << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    clock_t start = clock();

    bucket_sort(arr, n);

    clock_t end = clock();

    cout << "\n\nSorted Array:" << endl;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    double executionTime =
        ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    cout << "\n\nExecution Time: "
         << executionTime
         << " milliseconds" << endl;

    return 0;
}
// Original Array:
// 0.78 0.17 0.39 0.26 0.72 0.94 0.21 0.12 0.23 0.68 0.55 0.31 0.89 0.45 0.63 0.08 0.97 0.36 0.51 0.15 

// Sorted Array:
// 0.08 0.12 0.15 0.17 0.21 0.23 0.26 0.31 0.36 0.39 0.45 0.51 0.55 0.63 0.68 0.72 0.78 0.89 0.94 0.97 

// Execution Time: 0 milliseconds