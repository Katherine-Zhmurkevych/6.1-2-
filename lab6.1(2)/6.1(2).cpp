//рекурсивний метод 
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int* r, const int size, const int Low, const int High, int i)
{
	r[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		create(r, size, Low, High, i + 1);
}
void print(int* r, const int size, int i)
{
	cout << setw(4) << r[i];
	if (i < size - 1)
		print(r, size, i + 1);
	else
		cout << endl;
}
int sum(int* r, const int size, int i)
{
	if (i < size)
	{
		if (r[i] % 2 == 1 && r[i] % 13 != 0) {
			int elementOfArray=r[i];
			r[i] = 0;
			return elementOfArray + sum(r, size, i + 1);
		}
		else
			return sum(r, size, i + 1);
	}
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL)); 
	const int n = 23;
	int r[n];
	int Low = 4;
	int High = 68;
	create(r, n, Low, High, 0);
	print(r, n, 0);
	cout << "S = " << sum(r, n, 0) << endl;
	print(r, n, 0);
	return 0;
}