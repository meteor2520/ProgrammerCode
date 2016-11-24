#include <stdio.h>
#include <string.h>

/*Method one: Shift*/
void LeftShiftOne(char *s, int n)
{
    char t = s[0];
    for (int i = 1; i < n; i++)
    {
	s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

void LeftRotateString1(char *s, int n, int m)
{
    while(m--)
    {
	LeftShiftOne(s, n);
    }
}

/*Method two: 3 steps*/
void ReverseString(char *s, int from, int to)
{
    char t;
    while(from < to)
    {
	t = s[from];
	s[from++] = s[to];
	s[to--] = t;	
    }
}

void LeftRotateString2(char *s, int n, int m)
{
    m %= n;
    ReverseString(s, 0, m-1);
    ReverseString(s, m, n-1);
    ReverseString(s, 0, n-1);
}

int main(int argc, char *argv[])
{
    char str1[] = "abcdef";
    LeftRotateString1(str1, strlen(str1), 3);
    printf("str1 == %s\n", str1);
    char str2[] = "abcdefgh";
    LeftRotateString2(str2, strlen(str2), 4);
    printf("str2 == %s\n", str2);
    return 0;
}
