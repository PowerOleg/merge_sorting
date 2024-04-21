#include <iostream>

void merge_sort(int* arr, int size);
void copy(int* arr_source, int* arr_destination, int size);
int* merge(int* arr1, int* arr2, int size_arr1, int size_arr2);

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
	int size1 = 10;
	int* array1 = new int[size1]{3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	std::cout << "Исходный массив: ";
	print(array1, size1);
	merge_sort(array1, size1);
	std::cout << "\nОтсортированный массив: ";
	print(array1, size1);
	delete[] array1;
	return 0;
}

void merge_sort(int* arr, int size)
{
	if (size == 1)
	{
		return;
	}

	int half_first = size / 2;
	int half_second = size - half_first;
	int* array_first_half = new int[half_first];
	int* array_second_half = new int[half_second];
	if (half_first == half_second)
	{
		for (int i = 0, j = half_first; i < half_first; i++, j++)
		{
			array_first_half[i] = arr[i];
			array_second_half[i] = arr[j];
		}
	}
	else
	{
		for (int i = 0; i < half_first; i++)
		{
			array_first_half[i] = arr[i];
		}
		for (int j = half_first, k = 0; j < size; j++, k++)
		{
			array_second_half[k] = arr[j];
		}
	}
	
	// вызываем этот же метод и делим массив еще и еще пополам пока не останется 1 элемент
	merge_sort(array_first_half, half_first);
	merge_sort(array_second_half, half_second);
	//собираем вместе и сортируем
	int* sorted_arr = merge(array_first_half, array_second_half, half_first, half_second);
	copy(sorted_arr, arr, size);//нам нужно записать значения в первоначальный указатель
	delete[] array_first_half;
	delete[] array_second_half;
	delete[] sorted_arr;
}

int* merge(int* arr1, int* arr2, int size_arr1, int size_arr2)
{
	int* new_arr = new int[size_arr1 + size_arr2];
	int first_arr_count = 0;
	int second_arr_count = 0;
	int new_arr_count = 0;


	while (first_arr_count < size_arr1 || second_arr_count < size_arr2)
	{
		if (first_arr_count == size_arr1)
		{
			new_arr[new_arr_count] = arr2[second_arr_count];
			second_arr_count++;
		}
		else if (second_arr_count == size_arr2)
		{
			new_arr[new_arr_count] = arr1[first_arr_count];
			first_arr_count++;
		}
		else
		{


			if (arr1[first_arr_count] <= arr2[second_arr_count])
			{
				new_arr[new_arr_count] = arr1[first_arr_count];
				first_arr_count++;


			}
			else
			{
				new_arr[new_arr_count] = arr2[second_arr_count];
				second_arr_count++;
			}
		}

		new_arr_count++;
	}



	return new_arr;
}

void copy(int* arr_source, int* arr_destination, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr_destination[i] = arr_source[i];
	}
}