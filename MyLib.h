#pragma once

namespace MyLib
{
	float* createAndInitArr(const size_t size);

	void printArr(const float* arr, const size_t size);
	void printArr(const int* arr, const size_t size);

	void printPositiveAndNegative(const float* arr, const size_t size);

	void sortArr(int* arr, const size_t size);
}