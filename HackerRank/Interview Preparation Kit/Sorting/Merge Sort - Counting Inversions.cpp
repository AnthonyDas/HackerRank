#include <vector>
#include <iostream>

void Merge(long &count, std::vector<int> &arr, int start, int middle, int end) {
	const int totalElements = end - start + 1;
	std::vector<int> tempArray(totalElements);
	int mergedIndex = 0;

	// Index of left subarray arr[start, ..., middle]
	int leftIndex = start;

	// Index of right subarray arr[middle + 1, ..., end]
	int rightIndex = middle + 1;

	// Merge the two subarrays
	while (leftIndex <= middle && rightIndex <= end) {
		if (arr[leftIndex] <= arr[rightIndex]) {
			tempArray[mergedIndex] = arr[leftIndex];
			++leftIndex;
		}
		else {
			tempArray[mergedIndex] = arr[rightIndex];
			++rightIndex;

			// Increment the "swap" count
			count += middle - leftIndex + 1;
		}

		++mergedIndex;
	}

	// If there're any remaining element in left subarray
	// that is not stored to merged array yet
	while (leftIndex <= middle) {
		tempArray[mergedIndex] = arr[leftIndex];

		++leftIndex;
		++mergedIndex;
	}

	// If there're any remaining element in right subarray
	// that is not stored to merged array yet
	while (rightIndex <= end) {
		tempArray[mergedIndex] = arr[rightIndex];

		++rightIndex;
		++mergedIndex;
	}

	// Now, the merged array has been sorted
	// Copy the elements to the original array
	for (int i = 0; i < totalElements; ++i) {
		arr[start + i] = tempArray[i];
	}
}

void MergeSort(long &count, std::vector<int> &arr, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;

		// Sort left subarray arr[start ... middle]
		MergeSort(count, arr, start, middle);

		// Sort right subarray arr[middle + 1 ... end]
		MergeSort(count, arr, middle + 1, end);

		Merge(count, arr, start, middle, end);
	}
}

// Complete the countInversions function below.
long countInversions(std::vector<int> arr) {
	long count = 0;

	MergeSort(count, arr, 0, arr.size() - 1);

	return count;
}