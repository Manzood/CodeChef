#include <stdio.h>

int main()
{
	int t, k, n, c, i, j, flag, temp;

	scanf ("%d", &t);
	int pos;
	int sum = 0;
	
	while (t--)
	{
		scanf ("%d %d", &n, &k);

		int min[k];

		for (i = 0; i < k; i++)
		{
			scanf ("%d", &c);
			n--;

			for (j = 0; j <= i; j++)
			{
				if (c < min[j])
				{
					temp = c;
					c = min[j];
					min[j] = temp;
					flag = 1;
				}
			}

			if (flag == 1)
				flag = 0;

			else
				min[i] = c;
		}

		pos = k;

		while (n--)
		{
			scanf ("%d", &c);
			flag = 0;

			for (i = 0; i < k && flag == 0; i++)
			{
				if (c < min[i])
				{
					min[pos] = c;
					flag = 1;
					pos--;	
				}

				//printf ("%d\n", min[i]);
			}
		}

		for (i = 0; i < k; i++)
		{
			sum+=min[i];
			printf ("%d\n", min[i]);
		}

		printf ("%d\n", sum);
	}

	return 0;
}