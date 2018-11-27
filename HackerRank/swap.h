#pragma once

template <typename T>
void swap(T &lhs, T &rhs) noexcept {
	const T temp = lhs;
	lhs = rhs;
	rhs = temp;
}