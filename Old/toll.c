#include <stdio.h>

int main()
{
	int i, t, n, toll1[100000], toll2[100000], cost, loc, switch1[100000], switch2[100000];
	scanf ("%d", &t);

	while (t--)
	{
		cost = 0;
		scanf ("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf ("%d", &toll1[i]);
		}

		for (i = 0; i < n; i++)
		{
			scanf ("%d", &toll2[i]);
		}

		if (toll1[0] > toll2[0])
		{
			cost += toll2[0];
			loc = 2;
		}

		else
		{
			cost += toll1[0];
			loc = 1;
		}

		for (i = 0; i < n-1; i++)
		{
			scanf ("%d", &switch2[i]);
		}

		for (i = 0; i < n-1; i++)
		{
			scanf ("%d", &switch1[i]);
		}

		for (i = 0; i < n-1; i++)
		{
			if (loc == 1)
			{
				//printf ("%d %d %d\n", toll1[i+1], switch2[i], toll2[i+1]);
				if (toll1[i+1] < (switch2[i]+toll2[i+1]))
				{
					cost += toll1[i+1];
				}

				else
				{
					cost += (switch2[i]+toll2[i+1]);
					printf ("%d ", cost);
					loc = 2;
				}
			}

			if (loc == 2)
			{
				if (toll2[i+1] < (switch1[i] + toll1[i+1]))
				{
					cost += toll2[i+1];
				}

				else
				{
					cost += (switch1[i]+toll1[i+1]);
					loc = 1;
				}
			}
		}

		printf ("%d\n", cost);
	}
}