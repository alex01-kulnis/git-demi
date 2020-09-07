#include <iostream>
#include<chrono>
#define SIZE 10
using namespace std;

//сортировка Хоара
int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}

int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};

//сортировка выбором
void choicesSort(int A[], int size)
{
	int k, i, j;
	auto start = chrono::high_resolution_clock::now();
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1, k = i; j < size; j++)	
			if (A[j] < A[k])// менять знак для специального вывода(возр.(<) или (>)убывание)
				k = j;
		int c = A[k];
		A[k] = A[i];
		A[i] = c;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration " << duration.count() << " s" << endl;
}

//сортировка Шелла
void insertSort(int A[], int size)
{
	int t, i, j;
	auto start = chrono::high_resolution_clock::now();
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration " << duration.count() << " s" << endl;
}

//сортировка пузырьком
void buble(int b[],int n)
{
	auto start = chrono::high_resolution_clock::now();//класс high_resolution_clo метод now
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (b[r] < b[r + 1])
			{
				// Обмен местами
				int temp = b[r];
				b[r] = b[r + 1];
				b[r + 1] = temp;
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration " << duration.count() << " s" << endl;
}

//
void quickSort(int a[], int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = a[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((a[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			a[left] = a[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((a[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			a[right] = a[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	a[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(a, left, pivot - 1);
	if (right > pivot)
		quickSort(a, pivot + 1, right);
}

//base
void swap(int a[], int b[], int n)
{
	int max = 0, index;
	for (int i = 0; i < 10; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			index = i;
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (i >= index && i % 2 != 0)
		{
			b[i] = a[i];
		}
	}
}

//dop 13
void swap2(int a[], int b[], int n)
{
	int max = 0, index;
	for (int i = 0; i < 10; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			index = i;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (i >= index && i % 2 == 0)
		{
			b[i] = a[i];
		}
	}
}

//base 1
void base()
{
	setlocale(LC_ALL, "Rus");
	int size = 10, i;
	int A[SIZE] = { 1,2,3,4,5123,6,7,8,9,10 }, B[SIZE] = { 10,20,30,40,50,60,70,80,90,100 };

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> A[i];
	}*/

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> B[i];
	}*/

	cout << "Вывод массива A" << endl;
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << "Сработала функция" << endl;
	swap(A, B, size);

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	
	buble(B, size);
	
	cout << "Результирующий массив после сортировки пузырьком: ";
	for (i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;

	auto start2 = chrono::high_resolution_clock::now();
	getHoarBorder(B, 0, 0);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration2 = end2 - start2;
	cout << "Duration2 " << duration2.count() << " s" << endl;

	cout << "Результирующий массив после сортировки Хоара: ";
	for (i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;
}

//dop7
void dop1()
{
	setlocale(LC_ALL, "Rus");
	int size = 10, i, C[SIZE];
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 }, B[SIZE] = { 11,22,33,44,55,66,77,88,99,100 };

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> A[i];
	}*/

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> B[i];
	}*/
	
	cout << "Вывод массива A" << endl;
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;
	
	//записть в массив С
	for (int i = 0; i < 10; i++)
	{
		if (A[i] % 2 == 0)
		{
			C[i] = A[i];
		}

		if (B[i] % 2 != 0)
		{
			C[i] = B[i];
		}
	}

	cout << "Вывод массива C" << endl;
	for (i = 0; i < size; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;

	buble(C, size);

	cout << "Результирующий массив после сортировки пузырьком: ";
	for (i = 0; i < size; i++)
		cout << C[i] << " ";
	cout << endl;

	auto start2 = chrono::high_resolution_clock::now();
	getHoarBorder(C, 0, 0);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration2 = end2 - start2;
	cout << "Duration2 " << duration2.count() << " s" << endl;

	cout << "Результирующий массив после сортировки Хоара: ";
	for (i = 0; i < size; i++)
		cout << C[i] << " ";
	cout << endl;
}

//dop8
void dop2()
{
	setlocale(LC_ALL, "Rus");
	int size = 10, i, C[SIZE];
	int A[SIZE] = { 1,2,3,4,5,6,7,8,9,10 }, B[SIZE] = { 11,22,33,44,55,66,77,88,99,100 };

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> A[i];
	}*/

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> B[i];
	}*/

	cout << "Вывод массива A" << endl;
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	//записть в массив С
	for (int i = 0; i < 10; i++)
	{
		if (A[i] % 2 == 0)
		{
			C[i] = A[i];
		}

		if (B[i] % 2 != 0)
		{
			C[i] = B[i];
		}
	}

	cout << "Вывод массива C" << endl;
	for (i = 0; i < size; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;

	insertSort(C, size);
	cout << "Результирующий массив после сортировки Шелла: ";
	for (i = 0; i < size; i++)
		cout << C[i] << " ";
	cout << endl;

	choicesSort(C, size);
	cout << "Результирующий массив после сортировки выбором: ";
	for (i = 0; i < size; i++)
		cout << C[i] << " ";
	cout << endl;
}

//dop 13
void dop3()
{
	setlocale(LC_ALL, "Rus");
	int size = 10, i;
	int A[SIZE] = { 1,2,3,4,5123,6,7,8,9,10 }, B[SIZE] = { 10,20,30,40,50,60,70,80,90,100 };

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> A[i];
	}*/

	/*cout << "Ввод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << i + 1 << " элемент = ";
		cin >> B[i];
	}*/

	cout << "Вывод массива A" << endl;
	for (i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << "Сработала функция" << endl;
	swap2(A, B, size);

	cout << "Вывод массива B" << endl;
	for (i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;

	
	buble(B, size);
	cout << "Результирующий массив после сортировки пузырьком: ";
	for (i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;

	auto start2 = chrono::high_resolution_clock::now();
	getHoarBorder(B, 0, 0);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> duration2 = end2 - start2;
	cout << "Duration2 " << duration2.count() << " s" << endl;

	cout << "Результирующий массив после сортировки Хоара: ";
	for (i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;
}

void main()
{
	//base();
	//dop1();
	//dop2();
	//dop3();
}