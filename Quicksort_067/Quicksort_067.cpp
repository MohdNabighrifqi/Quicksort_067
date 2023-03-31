#include <iostream>
using namespace std;

//array if intergers to hold values
int arr[20];
int cmp_count = 0; //number of comparasion
int mov_count = 0; //number of data movement
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "/nmaksimum panjang array adalah 20" << endl;
	}

	cout << "\n===================" << endl;
	cout << "\nEnter array element" << endl;
	cout << "\n===================" << endl;
	
	for (int i = 0;i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
// swaps the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)                             //langkah algoritma 1
		return;

	//partition the list into two parts:
	//one containing elements less that or equal to pivot 
	//outher conntainning elements greather that pivot

	pivot = arr[low];                           //langkah algoritma 2

	i = low + 1;                                //langkah algoritma 3
	j = high;                                   //langkah algoritma 4

	while (i <= j)                                 //langkah algoritma 10
	{
		//search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high))        //langkah algoritma 5
		{
			i++;                                        //langkah algoritma 6
			cmp_count++;
		}
		cmp_count++;
		//search for al element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))          //langkah algoritma 7
		{
			j--;                                        //langkah algoritma 8
			cmp_count++;
		}
		cmp_count++;

		//if the greater element is on the left of the element
		if (i < j)                                      //langkah algoritma 9
	}
}


//j now containt the index of the last element in the sorted list
if (low < j)                                           //langkah algoritma 11
{

	//move the pivot to its correct position in the list
	swap(low, j);
	mov_count++;
}
//sort the list on the left of pivot using quick sort
q_short (low, j - 1);                                    //langkah algoritma 12

//sort the list on the right of pivot using quick sort
q_short (j + 1, high);                                    //langkah algoritma 13

}

void display() {
	cout << "\n==========" << endl;
	cout << "sorted array" << endl;
	cout << "============" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasion: " << cmp_count << endl;
	cout << "number of data movements:" << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);                      //sort the array using quick sort
	display();
	system("pause");

	return 0;
}
