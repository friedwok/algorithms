#include<iostream>

using namespace std;

int *bubble_sort(int *array, int array_size)
{
	int i = 0;
	int buf;
	char swap_cnt = 0;

	if(array_size == 0)
		return 0;
	while(i < array_size) {
		if((i+1 != array_size) && (array[i] > array[i+1])) {
			buf = array[i];
			array[i] = array[i+1];
			array[i+1] = buf;
			swap_cnt = 1;
		}
		i++;
		if(i == array_size && swap_cnt == 1) {
			swap_cnt = 0;
			i = 0;
		}
	}
	return array;
}

int main()
{
	int n;
	int *arr;

	cout << "arrsize = ";
	cin >> n;
	arr = new int[n];
	for(int i = 0; i < n; i++) {
		cout << "Input arr[" << i << "] = ";
		cin >> arr[i];
		//cout << endl;
	}

	arr = bubble_sort(arr, n);

	for(int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	return 0;
}
