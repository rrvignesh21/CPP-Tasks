#include<iostream>
using namespace std;
/* Write a C++ program to find the number of pairs of integers
 in a given array of integers whose sum is equal to a specified number. */
int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}
int noOfPairs(int array[],int size_of_Array,int sum){
    int count = 0;
    qsort(array,size_of_Array,sizeof(int),compare);
    for(int i = 0;i < size_of_Array - 1;i++){
        int temp = sum - array[i];
        if(binarySearch(array,temp,i+1,(size_of_Array-1)) != -1){
            count++;
        }
    }return count;
}

int main(){
     int size_of_Array;
    cout << "Enter the size of the Array : ";
    cin >> size_of_Array;
    int array[size_of_Array];
    cout << "Enter the Array elements : ";
    for (int i = 0; i < size_of_Array; i++)
    {
        cin >> array[i];
    }
    int target_sum_number;
    cout << "Enter Sum : ";
    cin >> target_sum_number;
    int count = noOfPairs(array,size_of_Array,target_sum_number);
    cout << "Number of pairs of integers in a given array of integers whose sum is equals " << target_sum_number << " is "<< count << endl;
}