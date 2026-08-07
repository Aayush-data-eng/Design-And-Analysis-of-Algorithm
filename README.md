# Design-And-Analysis-of-Algorithm
This is a course for Bsc Physical Science Students. The topics covered here will be related to the curriculum layed before the students.    

## Linear Search

- Also known as sequential search
- we have used a approach wherein the Time complexity: O(n) and Space Complexity: O(1)
- This algorithm is uesd for unsorted array or tiny array. 


- #### Best Case: In the best case, the key might be present at the first index. So the best case complexity is O(1)
- #### Worst Case: In the worst case, the key might be present at the last index i.e., opposite to the end from which the search has started in the list. So the worst--   case complexity is O(N) where N is the size of the list.
- #### Average Case: O(N)
- #### Auxiliary Space: O(1) as except for the variable to iterate through the list, no other variable is used.
#### Loop invariance: - 
<blockquote>At the start of each iteration, the target element is not present in the portion of the array that has already been searched (A[0...i−1]).</blockquote>

#### Proof: -
<pre>- Initialization: Before the first iteration (i = 0), no elements have been checked, so the statement is true.
- Maintenance: If the target is not found at index i, then after checking A[i], it is also not in A[0...i].
- Termination: If the loop ends without finding the target, then every element has been checked, so the target is not in the array.</pre>


## Binary Search 

<blockquote>Binary Search is a searching algorithm that operates on a sorted or monotonic search space, repeatedly dividing it into halves to find a target value or optimal answer in logarithmic time O(log N).</blockquote>

<img width="400" height="300" alt="image" src="https://github.com/user-attachments/assets/70fc2436-edd1-4e41-842e-a2b6eb639d71" />


### Conditions to apply Binary Search Algorithm in a Data Structure
- The data structure must be sorted.
- Access to any element of the data structure should take constant time.
### Binary Search Algorithm
- Divide the search space into two halves by finding the middle index "mid". 
- Compare the middle of the search space with the key. 
- If the key is found at middle, the process is terminated.
- If the key is not found at middle, choose which half will be used as the next search space.
- -> If the key is smaller than the middle, then the left side is used for next search.
- -> If the key is larger than the middle, then the right side is used for next search.
- This process is continued until the key is found or the total search space is exhausted.

### How does Binary Search Algorithm work?
<pre>To understand the working of binary search, consider the following illustration:

Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}, and the target = 23. </pre>

<pre><img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/8bfc914e-0a8f-4128-b3c8-ea9ac9af7576" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/0cc00145-e561-4bb0-a85b-cd0051059586" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/2e332b95-a79b-4768-87da-a53c5bcc09af" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/8190f26f-8b9b-474c-9c80-1d2c686fb2d6" /></pre>

### How to Implement Binary Search?
It can be implemented in the following two ways: -

- Iterative Binary Search Algorithm
- Recursive Binary Search Algorithm

### Iterative Algorithm: O(log n) Time and O(1) Space
#### <blockquote> Here we use a while loop to continue the process of comparing the key and splitting the search space in two halves. </blockquote>

### Recursive Algorithm: O(log n) Time and O(Log n) Space
#### <blockquote> Create a recursive function and compare the mid of the search space with the key. And based on the result either return the index where the key is found or call the recursive function for the next search space. </blockquote>

### Complexity Analysis
Time Complexity: 
<pre>- -> Best Case: O(1)
- -> Average Case: O(log N)
- -> Worst Case: O(log N) </pre>
Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(log N).

#### Loop Invariance: -
<blockquote>At the start of every iteration, if the target exists in the array, then it must lie within the current search interval A[low...high].</blockquote>

#### Proof: -
<pre>- Initialization: Initially, the search interval is the whole array.
- Maintenance: Depending on the comparison with the middle element, half of the interval is discarded without removing the possible location of the target.
- Termination: When low > high, the interval is empty, so the target is not present.</pre>


## Sorting

<blockquote>Sorting is the process of arranging data in a specific order most commonly in ascending or descending order. It can be applied to numbers, characters, strings, objects, or any form of structured data.
Sorting helps to:

- Organize data meaningfully
 -Enable faster searching (e.g., Binary Search)
- Simplify problem-solving in many algorithms (e.g., Greedy, Divide & Conquer)
- Make data more readable or presentable</blockquote>

### Insertion Sort: -O(n^2) Time and O(1) Space

#### Algorithm
<pre>Start from the second element and insert it into the correct position in the sorted left part.
Shift elements to make space for insertion.
Repeat for all elements.</pre>

<pre><img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/7f3e294b-bcfb-4f34-b9d8-e9d24d4f2809" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/2456d9b7-ff9a-4f32-9bd3-5a7706189f7f" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/8c061948-c8a9-4097-b698-ec4cdf2d58f2" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/22efc8ed-235d-4a26-8330-ccf7e00f0e6c" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/6e98ef9b-159b-4065-9e3c-0cadfd03d382" /></pre>

#### Loop Invariance
<blockquote>Before iteration i, the subarray A[0...i−1] is sorted.

- Initialization: Before the first iteration, the first element alone is sorted.
- Maintenance: The current element is inserted into its correct position in the sorted subarray, so A[0...i] becomes sorted.
- Termination: When the loop ends, the entire array is sorted.</blockquote>

### Bubble Sort: -O(n^2) Time and O(1) Space

#### Algorithm:
<pre>Repeatedly compare adjacent elements and swap if they are in the wrong order.
Keep bubbling the largest element to the end in each pass.
Continue until no more swaps are needed.</pre>

<pre><img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/da48ae0d-460c-4a70-b377-bca62e39d829" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/052b45cf-6b7e-49f7-bb29-6adb04af2fd8" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/09288301-b582-4a3e-b27d-a79ccbde76e6" /></pre>

#### Loop Invariance
<blockquote>Before each outer-loop iteration, the last i elements are already sorted and in their final positions.

- Initialization: Before the first pass, no elements are guaranteed to be sorted, so the invariant holds.
- Maintenance: Each pass moves the largest unsorted element to its correct position at the end, increasing the sorted suffix by one element.
- Termination: After all passes, every element is in its correct position, so the array is sorted.</blockquote>

### Selection Sort: -O(n^2) Time and O(1) Space

#### Algorithm:
<pre>- Find the minimum element and swap it with the first unsorted element.
- Repeat this for all positions in the array.
- Works by maintaining two subarrays: sorted and unsorted.</pre>

<pre><img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/30ca867e-a207-44aa-9f04-b562cab47e52" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/b87ef6b2-a88a-4844-86e6-12de1fa5267d" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/e03b42e6-e856-405d-864b-d6e272921415" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/0149df0a-4512-4db3-b5c2-4b93fb652075" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/95a2c377-7863-4e12-bcfb-38cf6349de44" /> <img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/b791cf10-2ec6-4164-8bfe-8270eafd532e" /></pre>

#### Loop Invariance
<blockquote>Before iteration i, the first i elements are the smallest i elements in sorted order.

- Initialization: Before the first iteration, no elements have been selected, so the invariant is true.
- Maintenance: The smallest element from the unsorted portion is selected and placed at position i, extending the sorted prefix.
- Termination: When the loop ends, all elements have been placed in their correct positions, so the array is sorted.</blockquote>







