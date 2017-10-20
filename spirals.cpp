#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/
void make_spiral(int a[MAX_SIZE - 1][MAX_SIZE - 1], int n, int start)
{
	int t, b, l, r, value;
	t = l = 0;
	b = r = n - 1;
	value = start + n*n - 1;
	while (l <= r && t <= b && value >= start)
	{
		for (int j = r; j >= l; j--)
		{
			a[b][j] = value--;
		}
		b--;
		for (int i = b; i >= t; i--)
		{
			a[i][l] = value--;
		}
		l++;
		for (int j = l; j <= r; j++)
		{
			a[t][j] = value--;
		}
		t++;
		for (int i = t; i <= b; i++)
		{
			a[i][r] = value--;
		}
		r--;
	}
	return;
}

void print_spiral(int a[MAX_SIZE - 1][MAX_SIZE - 1], int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << right << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void do_spiral(const int n, const int start)
{
	cout << "Spiral of size " << n
		<< " starting at " << start << endl;
	if (n % 2 == 0)
	{
		cout << "***** Error: Size " << n << " must be odd."<< endl << endl;
		return;
	}
	else if (n > MAX_SIZE)
	{
		cout << "***** Error: Size " << n << " must be less than 101." << endl << endl;
		return;
	}
	else if (start > MAX_START)
	{
		cout << "***** Error: Start " << start << " must be less than 50." << endl << endl;
		return;
	}
	else if (n == 1)
	{
		cout << endl;
		cout << right << setw(4) << start << endl << endl;
		return;
	}
	else
	{
		cout << endl;
		int a[MAX_SIZE - 1][MAX_SIZE - 1];
		make_spiral(a, n, start);
		print_spiral(a, n, n);
		return;
	}

}

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
    return 0;
}

