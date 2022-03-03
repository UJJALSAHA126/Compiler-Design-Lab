#include <bits/stdc++.h>
#include "needed.h"

using namespace std;

char prol[7][10] = {"S", "A", "A", "B", "B", "C", "C"};

char pror[7][10] = {"A", "Bb", "Cd", "aB", "@", "Cc", "@"};

char prod[7][10] = {"S->A", "A->Bb", "A->Cd", "B->aB", "B->@", "C->Cc", "C->@"};

char first[7][10] = {"abcd", "ab", "cd", "a@", "@", "c@", "@"};

char follow[7][10] = {"$", "$", "$", "a$", "b$", "c$", "d$"};

char table[5][6][10];

int numr(char c)

{
    switch (c)

    {

    case 'S':
        return 0;

    case 'A':
        return 1;

    case 'B':
        return 2;

    case 'C':
        return 3;

    case 'a':
        return 0;

    case 'b':
        return 1;

    case 'c':
        return 2;

    case 'd':
        return 3;

    case '$':
        return 4;
    }

    return 2;
}

int main()

{
    int i, j, k;
    system("cls");
    // for (i = 20; i < 40; i++)
    // {
    //     changeColor(i);
    //     cout << "Color = " << i << " ";
    // }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)

            strcpy(table[i][j], " ");
    }

    changeColor(34);
    cout << endl
         << "The following is the predictive parsing table for the following grammar : " << endl;

    changeColor(32);
    for (i = 0; i < 7; i++)
    {
        cout << prod[i] << endl;
        // printf("%s\n", prod[i]);
    }

    changeColor(33);
    cout << endl
         << "Predictive parsing table is";

    // fflush(stdin);

    for (i = 0; i < 7; i++)
    {

        k = strlen(first[i]);

        // for (j = 0; j < 10; j++)
        for (j = 0; j < k; j++)

            if (first[i][j] != '@')

                strcpy(table[numr(prol[i][0]) + 1][numr(first[i][j]) + 1], prod[i]);
    }

    for (i = 0; i < 7; i++)

    {
        if (strlen(pror[i]) == 1)

        {
            if (pror[i][0] == '@')
            {
                k = strlen(follow[i]);

                for (j = 0; j < k; j++)

                    strcpy(table[numr(prol[i][0]) + 1][numr(follow[i][j]) + 1], prod[i]);
            }
        }
    }

    strcpy(table[0][0], " ");

    strcpy(table[0][1], "a");

    strcpy(table[0][2], "b");

    strcpy(table[0][3], "c");

    strcpy(table[0][4], "d");

    strcpy(table[0][5], "$");

    strcpy(table[1][0], "S");

    strcpy(table[2][0], "A");

    strcpy(table[3][0], "B");

    strcpy(table[4][0], "C");

    changeColor(31);
    cout << endl
         << "--------------------------------------------------------" << endl;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)

        {
            printf("%*s", -10, table[i][j]);

            if (j == 5)

                cout << endl
                     << "--------------------------------------------------------" << endl;
        }
    }

    changeColor(37);
    cout << endl
         << endl;
    return 0;
}