#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int count_lines(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return -1;
    }
    int count = 0;
    char buffer[100];
    while (fgets(buffer, 100, file))
    {
        count++;
    }
    fclose(file);
    return count;
}

int count_words(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return -1;
    }
    int count = 0;
    char word[100];
    while (!feof(file))
    {
        fscanf(file, "%s", word);
        count++;
    }
    fclose(file);
    return count;
}

int count_bytes(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    if (file == NULL)
    {
        return -1;
    }
    int count = 0;
    while (fgetc(file) != EOF)
    {
        count++;
    }
    fclose(file);
    return count;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("error");
    }
    else
    {
        setlocale(LC_ALL, "Rus");
        int result;
        if ((strcmp(argv[1], "--lines") == 0) || (strcmp(argv[1], "-l") == 0))
        {
            result = count_lines(argv[2]);
        }
        else
        {
            if ((strcmp(argv[1], "--words") == 0) || (strcmp(argv[1], "-w") == 0))
            {
                result = count_words(argv[2]);
            }
            else
            {
                if ((strcmp(argv[1], "--bytes") == 0) || (strcmp(argv[1], "-c") == 0))
                {
                    result = count_bytes(argv[2]);
                }
                else
                {
                    printf("error");
                }
            }
        }
        if (result != -1)
            printf("%d\n", result);
        else
            printf("error");
    }
    return 0;
}