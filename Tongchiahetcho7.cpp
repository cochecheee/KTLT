
#include <iostream>
#include <vector>

using namespace std;

//Tim tong lon nhat chia het cho 7
int maxSumdivided7(int a[100], int n, int& maxsum);

int main()
{
	int a[100];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	int maxsum = maxSumdivided7(a, n, maxsum);
	
	cout << maxsum;
}

int maxSumdivided7(int a[100], int n, int& maxsum)
{
	int i;
	vector<bool>b(n, 0);
	do {
		i = n - 1;
		while (b[i]==1)
		{
			b[i] = 0;
			i--;
		}

		if (i >= 0)
			b[i] = 1;

		int sum = 0;
		for (int i = 0; i < n; i++)
			if (b[i]==1)
				sum += a[i];

		if (sum % 7 == 0)
			maxsum = max(sum, maxsum);

	} while (i >= 0);

	return maxsum;
}