#include <stdio.h> 

int main() 
{ 
    int t, n, c;
    int i, j;
    int odd, even;
    scanf ("%d", &t);
    while (t--)
    {
        odd = 0;
        even = 0;
        scanf ("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf ("%d", &c);
            if ((c % 2) == 1)
                odd++;
            else
                even++;
        }
        
        printf ("%d\n", even*odd);
    }
    return 0; 
}