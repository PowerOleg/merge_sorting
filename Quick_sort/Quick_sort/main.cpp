#include <iostream>

void quick_sort(int* arr, int index1, int size);
int pivoting(int* arr, int index1, int size);


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
	int* array1 = new int[size1] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	std::cout << "Исходный массив: ";
	print(array1, size1);
	quick_sort(array1, 0, size1-1);
	std::cout << "\nОтсортированный массив: ";
	print(array1, size1);
	delete[] array1;
	return 0;
}

void quick_sort(int* arr, int index1, int size)
{
	if ((size - index1) <= 1)
	{
		return;
	}
	//int pivot = arr[(size - index1) / 2];
	int border = pivoting(arr, index1, size);//для диапазона массива от 2 до 4 граница должна быть 3 а тут 2

	quick_sort(arr, index1, border);
	quick_sort(arr, border, size);
}


/*int pivoting(int* arr, int index1, int size, int pivot)
{
	int left_count = index1;
	int right_count = size - 1;

	while (true)
	{
		while (arr[left_count] < pivot)
		{
			left_count++;
		}
		while (arr[right_count] > pivot)
		{
			right_count--;
		}
		if (left_count >= right_count)
		{
			return left_count;
		}
		else
		{
			int temp;
			temp = arr[left_count];
			arr[left_count] = arr[right_count];
			arr[right_count] = temp;
		}
		left_count++;
		right_count--;
	}
	return 0;
}
*/
int pivoting(int* arr, int l, int r)
{
	int left = l; int right = r;
	int pivot = l;
	bool go_left = true;
	bool go_right = false;
	while (left < right)
	{
		if (arr[right] <= arr[pivot] && go_left) {
			std::swap(arr[right], arr[pivot]);
			pivot = right;
			left++;
			go_left = false;
			go_right = true;
		}
		else if (go_left)
		{
			right--;
		}
		if (arr[left] > arr[pivot] && go_right)
		{
			std::swap(arr[left], arr[pivot]);
			pivot = left;
			right--;
			go_left = true;
			go_right = false;
		}
		else if (go_right)
		{
			left++;
		}
	}
	return pivot;
}