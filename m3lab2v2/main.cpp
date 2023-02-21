//Carlos Castilla Virelles
//2.20.23
//m3lab2
//csc 249
#include <iostream>
#include <string>
using namespace std;
bool DEBUG = true;
static int SWAPS = 0; // and time we switched "fingers" when merging
static int COMPS = 0; // any if statement comparing L' and R'
static int COPIES = 0; // # of copy operations into a temp array
string ArrayToString(int* array, int arraySize) ;
void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numbers
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position

   if (DEBUG) {

    cout <<"\tCalling Merge(" << leftFirst << "," << leftLast <<")"<<leftLast <<") with (" << leftLast+1 <<"," << rightLast <<")"<< endl;
   }

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= leftLast && rightPos <= rightLast) {
      COMPS++;
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
         SWAPS++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
         SWAPS++;
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
   // if we t racked COPY_OPERATIONS< this would be COPY_OPERATIONS += mergedSize
   COPIES += mergedSize;
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }
   cout <<"TEMP: " << ArrayToString(mergedNumbers, mergedSize) << endl;

   // Free temporary array
   delete[] mergedNumbers;
}

void MergeSort(int* numbers, int startIndex, int endIndex) {
   if (startIndex < endIndex) {
        if (DEBUG){
            cout <<"calling MergeSort(" << startIndex << "," << endIndex << ")" << endl;
        }
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numbers, startIndex, mid);
      MergeSort(numbers, mid + 1, endIndex);

      // Merge left and right partition in sorted order
      Merge(numbers, startIndex, mid, endIndex);
      if(DEBUG){
        cout <<"Ops so far:" << "comps=" << COMPS << " swaps=" << SWAPS<< " copies" << COPIES << endl;
      }
   }
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

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Numbers entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

   int numbersSize = sizeof(arr) / sizeof(arr[0]);

   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(arr, numbersSize) << endl;

   // Call the MergeSort function
   MergeSort(arr, 0, numbersSize - 1);

   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(arr, numbersSize) << endl;
}
