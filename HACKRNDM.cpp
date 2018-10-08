#include <stdio.h>
#include <algorithm>
using namespace std;

	int binarySearch(int arr[], int startIndex, int endIndex, int element) {
		if (startIndex > endIndex) {
			return 0;
		}
		int mid = startIndex + ((endIndex - startIndex) / 2);
		if (arr[mid] == element) {
			return 1;
		}
		if (element > arr[mid]) {
			return binarySearch(arr, mid + 1, endIndex, element);
		} else {
			return binarySearch(arr, startIndex, mid - 1, element);
		}
	}

int main() {
	
	
	int size;
	scanf("%d",&size);
	int arr[size];
	int difference;
	scanf("%d",&difference);
	
	for (int i = 0; i < size; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+size);
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		count += binarySearch(arr, i + 1, size - 1, arr[i]+difference);
	}
	
	printf("%d\n",count);

	return 0;
}
