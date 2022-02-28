#include <bits/stdc++.h>

using namespace std;

bool isDelimiter(char);
bool isOperator(char);
bool isValidIdentifier(char *);
bool iskeyword(char *);
char *subString(char *, int, int);
bool isDigit(char ch);
bool isInteger(char *str);
bool isRealNumber(char *);
void parse(char *);
void changeColor(int);

void changeColor(int color)
{
    printf("\033[1;%dm", color);
}

bool isDelimiter(char ch)
{
    char op[] = {' ', '+', '-', '*', '/', ',', ';', '>', '<', '=', '(', ')', '[', ']', '{', '}'};
    int len = sizeof(op) / sizeof(char);
    for (int i = 0; i < len; i++)
    {
        if (ch == op[i])
            return true;
    }
    return false;
}

bool isOperator(char ch)
{
    char op[] = {'+', '-', '*', '/', '>', '<', '='};
    int len = sizeof(op) / sizeof(char);
    for (int i = 0; i < len; i++)
        if (ch == op[i])
            return true;

    return false;
}

bool isValidIdentifier(char *str)
{
    char ch = str[0];
    return (isDigit(ch) || isDelimiter(ch));
    //     return true;
    // return false;

    // if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0' || isdeluminator(str[0]) == true)
    //     return (true);
    // return (false);
}

bool iskeyword(char *ch)
{

    string keys[] = {"int", "float", "double", "long", "char", "for", "while",
                     "if", "else", "printf", "scanf", "break", "short", "byte",
                     "do", "continue", "return", "switch", "case", "sizeof",
                     "typedef", "unsigned", "void", "static", "struct", "union", "goto"};
    string str = "";
    for (int i = 0; ch[i] != '\0'; i++)
        str += ch[i];
    for (string s : keys)
    {
        if (s == str)
            return true;
    }
    return false;

    // if (!strcmp(ch, "int") || !strcmp(ch, "if") || !strcmp(ch, "else") || !strcmp(ch, "while") || !strcmp(ch, "do") || !strcmp(ch, "break") || !strcmp(ch, "continue") || !strcmp(ch, "int") || !strcmp(ch, "float") || !strcmp(ch, "double") || !strcmp(ch, "return") || !strcmp(ch, "char") || !strcmp(ch, "case") || !strcmp(ch, "sizeof") || !strcmp(ch, "long") || !strcmp(ch, "short") || !strcmp(ch, "typedef") || !strcmp(ch, "sign") || !strcmp(ch, "unsign") || !strcmp(ch, "switch") || !strcmp(ch, "void") || !strcmp(ch, "static") || !strcmp(ch, "struct") || !strcmp(ch, "goto"))
    // {
    //     return (true);
    // }
    // return (false);
}

char *subString(char *str, int left, int right)
{
    int i;
    char *subString = (char *)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
    {
        subString[i - left] = str[i];
    }
    subString[right - left + 1] = '\0';
    return subString;
}

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isInteger(char *str)
{
    int len, i;
    len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (!isDigit(str[i]) && (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

bool isRealNumber(char *str)
{
    int len, i;
    bool hasDecimal = false;
    len = strlen(str);
    if (len == 0)
        return (false);

    for (i = 0; i < len; i++)
    {
        if ((!isDigit(str[i]) && str[i] != '.') || (str[i] == '-' && i > 0))
            return false;
        if (str[i] == '.')
            hasDecimal = true;
    }
    // for (i = 0; i < len; i++)
    // {
    //     if ((str[i] != '1' && str[0] != '2' && str[0] != '3' && str[0] != '4' && str[0] != '5' && str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9' && str[0] != '0' && str[i] != '.') || (str[i] == '-' && i > 0))
    //         return (false);
    //     if (str[i] == '.')
    //         hasDecimal = true;
    // }
    return hasDecimal;
}
