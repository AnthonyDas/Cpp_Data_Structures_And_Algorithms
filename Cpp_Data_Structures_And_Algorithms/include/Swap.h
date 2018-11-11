#pragma once

template <typename T>
void swap(T &l, T &r) noexcept {
	T temp = l;
	l = r;
	r = temp;
}