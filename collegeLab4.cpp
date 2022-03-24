#include <bits/stdc++.h>
using namespace std;

char s[20], stackk[20];

int main()
{
    system("cls");
    string m[5][6] = {"tb", " ", " ", "tb", " ", " ", " ", "+tb", " ", " ", "n", "n", "fc", " ", " ", "fc", " ", " ", " ", "n", "*fc", " a ", "n", "n", "i", " ", " ", "(e)", " ", " "};

    int size[5][6] = {2, 0, 0, 2, 0, 0, 0, 3, 0, 0, 1, 1, 2, 0,
                      0, 2, 0, 0, 0, 1, 3, 0, 1, 1, 1, 0, 0, 3, 0, 0};

    int i, j, k, n, str1, str2;

    cout<< "Enter the input string: ";
    // scanf("%s", s);
    cin >> s;
    strcat(s, "$");
    n = strlen(s);

    stackk[0] = '$';
    stackk[1] = 'e';

    i = 1;
    j = 0;

    cout << endl
         << "Stack     Input" << endl;
    cout << "__________________" << endl;

    while ((stackk[i] != '$') && (s[j] != '$'))
    {
        if (stackk[i] == s[j])
        {
            i--;
            j++;
        }
        switch (stackk[i])
        {
        case 'e':
            str1 = 0;
            break;
        case 'b':
            str1 = 1;
            break;
        case 't':
            str1 = 2;
            break;
        case 'c':
            str1 = 3;
            break;
        case 'f':
            str1 = 4;
            break;
        }

        switch (s[j])
        {
        case 'i':
            str2 = 0;
            break;
        case '+':
            str2 = 1;
            break;
        case '*':
            str2 = 2;
            break;
        case '(':
            str2 = 3;
            break;
        case ')':
            str2 = 4;
            break;
        case '$':
            str2 = 5;
            break;
        }

        if (m[str1][str2][0] == '\0')
        {
            cout << endl
                 << "ERROR";
            exit(0);
        }
        else if (m[str1][str2][0] == 'n')
            i--;
        else if (m[str1][str2][0] == 'i')
            stackk[i] = 'i';
        else
        {
            for (k = size[str1][str2] - 1; k >= 0; k--)
            {
                stackk[i] = m[str1][str2][k];
                i++;
            }
            i--;
        }

        for (k = 0; k <= i; k++)
            cout << stackk[k];
        cout << "       ";

        for (k = j; k <= n; k++)
            cout << s[k];
        cout << endl;
    }

    cout << endl
         << "SUCCESS";

    return 0;
}