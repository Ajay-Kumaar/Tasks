int c;
for(int i=0; i<limit-1 ;i++)
{
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        str[i] = c;
}
