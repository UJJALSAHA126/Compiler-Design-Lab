#include <bits/stdc++.h>
using namespace std;

int main()
{

    // for (int i = 30; i < 40; i++)
    // {
    //     printf("\033[1;%dm", i);
    //     printf("Number = [%d] ", i);
    // }
    // string keys[] = {"int", "float", "double", "long", "char", "for", "while"};
    // char * str = (char *)malloc(50);
    // cout<<"Enter A Name : ";
    // cin>>str;
    // string m = "";
    // for (int i = 0; str[i] != '\0'; i++)
    //     m += str[i];

    // cout<<(m=="hello");
    // for (string s : keys)
    // {
    //     cout << s << " ";

    //     if (s == "double")
    //     {
    //         cout << "Match";
    //     }
    // }
    // for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
    //     cout << keys[i] << " ";
    char ch;
    FILE *f1;
    f1=fopen("input.txt","r");
    while ((ch=getc(f1)) != EOF)
    {
        cout<<ch;
    }
    fclose(f1);
    return 0;
}