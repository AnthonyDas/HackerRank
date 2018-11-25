#pragma once

#include <vector>

class MinBinaryHeap {

	std::vector<int> vec;
	int m_size;

public:

	MinBinaryHeap() : m_size(0) {
		// Root will be at index 1
		vec.push_back(-1);
	};

	bool empty() {
		return m_size == 0;
	}

	void insert(const int &key) {
		++m_size;

		// Store the key in the vector last position
		if (m_size >= (int)vec.size()) {
			// Need to add a new element
			vec.emplace_back(key);
		}
		else {
			vec[m_size] = key;
		}
			
		shiftUp(m_size);
	}

	int peep() {
		return empty() ? -1 : vec[1];
	}

	int pop() {
		if (empty()) { return; }

		int minVal = vec[1];

		--m_size;

		// Swap with the last existing leaf
		std::swap(vec[1], vec[m_size]);

		// Fix heap property downwards
		shiftDown(1);

		return minVal;
	}

private:

	// Helper navigation functions
	int p(int i) { return i >> 1; } // Parent i/2
	int l(int i) { return i << 1; } // Left-child i*2
	int r(int i) { return (i << 1) + 1; } // Right-child i*2+1

	void shiftUp(int index) {
		// Do nothing in root
		if (index == 1) { return; }

		if (vec[index] < vec[p(index)]) {
			std::swap(vec[index], vec[p(index)]);

			// Recurse until root
			shiftUp(p(index));
		}
	}

	void shiftDown(int i) {
		// For non-existing index do nothing
		if (i > m_size) { return; }

		int swapId = i;

		// Compare with left child, if exists
		if (l(i) <= m_size && vec[i] > vec[l(i)])
			swapId = l(i);

		// Compare with right child, if exists
		if (r(i) <= m_size && vec[swapId] > vec[r(i)])
			swapId = r(i);

		// Swap with the larger of the two children
		if (swapId != i) {
			std::swap(vec[i], vec[swapId]);

			// Recurse until the index
			shiftDown(swapId);
		}
	}
};
