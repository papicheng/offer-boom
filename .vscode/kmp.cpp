#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void getNext(char *p, int *next)
{
	next[0] = -1;
	int i = 0;
	int j = -1;

	int len = strlen(p);
	while (i < len) {
		if (-1 == j || p[i] == p[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int kmp(char *t, char *p, int *next)
{
	int i = 0;
	int j = 0;

	int m = strlen(t);
	int n = strlen(p);
	while ((i < m) && (j < n)) {
		if (j == -1 || t[i] == p[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == n)
		return (i-j);
	else
		return -1;
}

int main()
{
	char str1[] = "aaddeongaswabdededeabdede";
	char str2[] = "abdede";

	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int *next = new int[length2 + 1]();
	getNext(str2, next);

	char *ptr = str1;

	int t = 0;
	int count = 0, index = 0;
	int i = 0;
	while (i < length1)
	{
		t = kmp(ptr, str2, next);

		if (t != -1)
		{
			++count;
			if (1 == count)
				index = t + 1;

			t += length2;
			ptr += t;
			i += t;
		}
		else
		{
			break;
		}
	}

	cout << count << " " << index << endl;

	delete[] next;

	return 0;
}
