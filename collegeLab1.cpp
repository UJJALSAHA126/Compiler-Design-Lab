#include <bits/stdc++.h>
#include "needed.h"

using namespace std;
const int defColor = 30;

void keyword(char str[10]);

void keyword(char str[10])
{
    changeColor(36);
    if (iskeyword(str))
    {
        cout << "\n"
             << str << " Is A Keyword." << endl;
    }
    else
    {
        cout << "\n"
             << str << " Is An Identifier." << endl;
    }
    changeColor(defColor);
}

int main()
{
    system("cls");
    // for(int i=30; i<40; i++){
    //     changeColor(i);
    //     cout<<"I = "<<i<<" ";
    // }

    changeColor(defColor);
    FILE *f1, *f2, *f3;
    char c, str[10], str1[10];
    int num[100], lineno = 0, tokenvalue = 0, i = 0, j = 0, k = 0;

    // cout << "Enter the C Program : ";
    // // cin>>str1;
    // f1 = fopen("input.txt", "w");
    // while ((c = getchar()) != EOF)
    // {
    //     putc(c, f1);
    // }
    // fclose(f1);

    f1 = fopen("input.txt", "r");
    f2 = fopen("identifier.txt", "w");
    f3 = fopen("specialchar.txt", "w");

    int m = 0;
    // c = getc(f1);
    // cout << "Start !" << endl;
    while ((c = getc(f1)) != EOF)
    {
        // cout << c << " ";
        if (isdigit(c))
        {
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c))
            {
                tokenvalue = tokenvalue * 10 + c - '0';
                c = getc(f1);
            }
            num[i++] = tokenvalue;
            tokenvalue = 0;
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            putc(c, f2);
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                putc(c, f2);
                c = fgetc(f1);
            }
            putc('.', f2);
            ungetc(c, f1);
        }
        else if (c == ' ' || c == '\t')
        {
            cout << "*";
        }
        else if (c == '\n')
        {
            lineno++;
        }
        else
        {
            putc(c, f3);
        }
        // c = getc(f1);
    }
    // cout << "Done !" << endl;

    fclose(f1);
    fclose(f2);
    fclose(f3);

    cout << "\nThe  no's in the programm are : ";
    changeColor(35);
    for (j = 0; j < i; j++)
    {
        cout << num[j] << " ";
    }
    changeColor(defColor);
    cout << endl;
    f2 = fopen("identifier.txt", "r");
    k = 0;
    cout << "\nThe Keywords and Identifiers are : ";
    changeColor(33);
    while ((c = getc(f2)) != EOF)
    {
        if (c != '.')
            str[k++] = c;
        else
        {
            str[k] = '\0';
            keyword(str);
            k = 0;
        }
    }
    fclose(f2);
    f3 = fopen("specialchar.txt", "r");
    changeColor(defColor);
    cout << "\nSpecial characters are : ";
    changeColor(32);
    while ((c = getc(f3)) != EOF)
    {
        cout << c << " ";
    }
    cout << endl;
    fclose(f3);
    changeColor(defColor);
    cout << "\nTotal no. of lines are : ";
    changeColor(31);
    cout << lineno;
    changeColor(defColor);
    return 0;
}