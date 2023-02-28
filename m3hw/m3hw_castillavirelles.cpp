//Carlos Castilla Virelles
//2.20.23 Silver
//m3hw
//csc 249
#include <iostream>
#include <string>
using namespace std;
bool DEBUG = true;
void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numbers
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
      }
      mergePos++;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
   }

   // Copy merged numbers back to numbers
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }

   // Free temporary array
   delete[] mergedNumbers;
}

void MergeSort(int* numbers, int startIndex, int endIndex) {
   if (startIndex < endIndex) {
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numbers, startIndex, mid);
      MergeSort(numbers, mid + 1, endIndex);

      // Merge left and right partition in sorted order
      Merge(numbers, startIndex, mid, endIndex);
   }
}
void BubbleSort(int* numbers, int startindex, int endindex) {
    int numSwaps = 0;
    for (int i = startindex; i < endindex; ++i) {
        bool swapped = false;
        for (int j = startindex; j < endindex-i-1; ++j) {
            if (numbers[j] > numbers[j+1]) { // if int is greater than next int in array, swap places with the next int
                swap(numbers[j], numbers[j+1]);
                cout << "Swapped " << numbers[j] << " and " << numbers[j+1] << endl;
                numSwaps++;
                swapped = true;
            }
          cout << "Compared " << numbers[j] << " and " << numbers[j+1] << endl;
        }
        if (!swapped) {
            break;
        }
    }
    cout << "Total number of swaps: " << numSwaps << endl;
}

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }

   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);

   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }

   // Add closing ']' and return result
   result += "]";
   return result;
}

int main() {
   
    int n; 
    cout << "How many numbers would you like to sort? ";
    cin >> n;

    int* arr = new int[n]; 

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Numbers entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(arr, n) << endl;

   // Call the BubbleSort function
   BubbleSort(arr, 0, n);

   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(arr, n) << endl;

   // Free the dynamically allocated memory
   delete[] arr;

   return 0;
}