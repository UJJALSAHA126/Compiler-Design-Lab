#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isDeluminator(char ch)
{
    char op[] = {' ', '+', '-', '*', '/', ',', ';', '>', '<', '=', '(', ')', '[', ']', '{', '}', '?', '!', ':'};
    int len = sizeof(op) / sizeof(char);
    for (int i = 0; i < len; i++)
    {
        if (ch == op[i])
            return true;
    }
    return false;

    // if (ch == '' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '?' || ch == '!' || ch == ':')
    // {
    //     return (true);
    //     return (false);
    // }
}
bool isOperator(char ch)
{
    char op[] = {'+', '-', '*', '/', '?', '!', ':'};
    int len = sizeof(op) / sizeof(char);
    for (int i = 0; i < len; i++)
        if (ch == op[i])
            return true;

    return false;
    // if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '?' || ch == '!' || ch == ':')
    // {
    //     return (true);
    //     return (false);
    // }
}
bool isvalididentifier(char *str)
{
    char ch = str[0];
    if ((ch >= '0' && ch <= '9') || isdeluminator(ch) == true)
        return false;
    return true;

    // if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0' || isdeluminator(str[0]) == true)
    //     return (true);
    // return (false);
}
bool iskeyword(char *ch)
{
    if (!strcmp(ch, "int") || !strcmp(ch, "if") || !strcmp(ch, "else") || !strcmp(ch, "while") || !strcmp(ch, "do") || !strcmp(ch, "break") || !strcmp(ch, "continue") || !strcmp(ch, "int") || !strcmp(ch, "float") || !strcmp(ch, "double") || !strcmp(ch, "return") || !strcmp(ch, "char") || !strcmp(ch, "case") || !strcmp(ch, "sizeof") || !strcmp(ch, "long") || !strcmp(ch, "short") || !strcmp(ch, "typedef") || !strcmp(ch, "sign") || !strcmp(ch, "unsign") || !strcmp(ch, "switch") || !strcmp(ch, "void") || !strcmp(ch, "static") || !strcmp(ch, "struct") || !strcmp(ch, "goto") )
    {
        return (true);
    }
    return (false);
}
bool isInteger(char *str)
{
    int len, i;
    len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9') && (str[i] == '-' && i > 0))
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
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' && (str[i] == '-' && i > 0))
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

char *subString(char *str, int left, int right)
{
    int i;
    char *subStr = (char *)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
    {
        subStr[i - left] = str[i];
    }
    subStr[right - left + 1] = '\0';
    return subStr;
}
