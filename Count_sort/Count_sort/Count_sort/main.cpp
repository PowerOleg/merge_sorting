#include <iostream>

void count_sort(int *&arr, int size, int left_bound, int right_bound);

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int size1 = 4;
	int* array1 = new int[size1] {13, 12, 11, 10};
	int left_bound = 10;
	int right_bound = 14;
	std::cout << "Исходный массив: ";
	print(array1, size1);
	count_sort(array1, size1, left_bound, right_bound);
	std::cout << "\nОтсортированный массив: ";
	print(array1, size1);
	delete[] array1;
	return 0;
}

void count_sort(int *&arr, int size, int left_bound, int right_bound)
{
	int counts_size = right_bound - left_bound;
	int* counts = new int[right_bound]{};
	for (size_t i = 0; i < size; i++)
	{
		counts[arr[i]]++;
	}
	size_t c = 0;
	for (size_t i = 0; i < counts_size; i++)
	{
		while (counts[c] == 0)
		{
			c++;
		}
		arr[i] = c;
		counts[c]--;
	}
}