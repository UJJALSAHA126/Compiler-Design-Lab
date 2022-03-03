#include <bits/stdc++.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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
    // cout<<"\033[1;%dm";
}

bool isDelimiter(char ch)
{
    char op[] = {' ', '+', '-', '*', '/', ',', ';', '>', '<', '=', '(', ')', '[', ']', '{', '}'};
    int len = sizeof(op) / sizeof(char);
    for (char c : op)
    {
        if (ch == c)
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

void parse(char *str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right)
    {
        if (!isDelimiter(str[right]))
            right++;

        if (isDelimiter(str[right]) && left == right)
        {
            if (isOperator(str[right]))
                cout << str[right] << " Is An Operator" << endl;
            // right++;
            // left = right;
            left = ++right;
        }
        else if (isDelimiter(str[right]) && (left != right) || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (iskeyword(subStr))
            {
                changeColor(36);
                cout << subStr;
                changeColor(34);
                cout << " Is A Keyword" << endl;
                changeColor(37);
            }
            else if (isInteger(subStr))
            {
                changeColor(36);
                cout << subStr;
                changeColor(34);
                cout << " Is A Integer" << endl;
                changeColor(37);
            }
            else if (isRealNumber(subStr))
            {
                changeColor(36);
                cout << subStr;
                changeColor(34);
                cout << " Is A Real Number" << endl;
                changeColor(37);
            }
            else if (isValidIdentifier(subStr))
            {
                changeColor(36);
                cout << subStr;
                changeColor(34);
                cout << " Is A Valid Identifier" << endl;
                changeColor(37);
            }
            else if (!isValidIdentifier(subStr) && !isDelimiter(str[right - 1]))
            {
                changeColor(36);
                cout << subStr;
                changeColor(34);
                cout << " Is A Valid Identifier and Not A Valid Delimiter" << endl;
                changeColor(37);
            }

            left = right;
        }
    }
}

int main()
{
    // system("cls");
    // changeColor(37);
    // char *str = (char *)malloc(100);
    // cout << "Enter : ";
    // scanf("%[^\n]", str);
    // strcpy(str, "float d=b+1c;");/
    char str[100] = "float d = b + 1c;";
    cout << "The String Is : " << str << endl;
    changeColor(33);
    cout << "----------------------******************--------------------" << endl;
    changeColor(31);
    cout << "Loading Please Wait ........../";
    char t[] = {'/', '-', '\\'};
    int t1 = 0;
    for (int i = 0; i < 7; i++)
    {
        cout << "\b" << t[t1];
        if (t[t1] == '-')
            Sleep(190);
        else
            Sleep(400);
        t1 = (t1 + 1) % (sizeof(t) / sizeof(char));
    }
    changeColor(32);
    cout << endl
         << "Done ---------->>>>>" << endl
         << endl;
    changeColor(37);

    parse(str);
    return 0;
}