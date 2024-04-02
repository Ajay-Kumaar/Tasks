#include <stdio.h>
void filecmp(FILE *fp1, FILE *fp2)
{
    int c1, c2;
    while (1)
	{
        if ((c1 = getc(fp1)) == EOF)
            break;
        if ((c2 = getc(fp2)) == EOF)
            break;
        if (c1 != c2)
		{
            putchar(c1);
            putchar(c2);
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    if (argc == 1)
	{
        printf("Please provide two files");
        return 1;
    }
	else
        while (--argc > 0)
		{
            if ((fp1 = fopen(argv[1], "r")) == NULL)
			{
                printf("Can't open the file, %s\n", argv[1]);
                return 1;
            }
            if ((fp2 = fopen(argv[2], "r")) == NULL)
			{
                printf("Can't open the file, %s\n", argv[2]);
                return 1;
            }
            filecmp(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
        }
    return 0;
}
