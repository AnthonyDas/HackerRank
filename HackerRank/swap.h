#pragma once

template <typename T>
void swap(T &lhs, T &rhs) {
	const T temp = lhs;
	lhs = rhs;
	rhs = temp;
}