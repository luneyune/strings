#include <stdio.h>
#include <string.h>

char check(char ch)
{
    if (ch == '\0') return 1;
    if (ch >= ' ' && ch <= '~') return 1;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage:\nstrings <filename>\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    char strbuff[1000];
    char *strbufp = strbuff;
    int ch = fgetc(file);
    while (ch != EOF) {
        if (!check(ch)) {
            strbufp = strbuff;
            ch = fgetc(file);
            continue;
        }

        *strbufp = ch;
        strbufp++;
        if (ch == '\0') {
            if (strbuff[0] != '\0' && (strlen(strbuff) > 2)) {
                printf("%s\n", strbuff);
            }
            strbufp = strbuff;
        }
        ch = fgetc(file);
    }
    fclose(file);
}