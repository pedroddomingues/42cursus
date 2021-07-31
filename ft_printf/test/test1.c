#include <stdio.h>
#include <time.h>

int main(void)
{
    int i;
    char str[1000000];

    i = 0;
    while (i < 1000000)
    {
        str[i] = 'x';
        i++;
    }
    i = 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("starting: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    while (i < 1000000)
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\nending: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}