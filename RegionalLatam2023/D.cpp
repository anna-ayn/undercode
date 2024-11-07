#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    cin >> s[0]; // secret word

    map<char, int> appear_letter_in_secret_word;
    for (int i = 0; i < 5; i++)
        appear_letter_in_secret_word[s[0][i]]++;

    map<string, int> freq;
    freq["*****"] = 1;

    // leer las otras palabras
    for (int i = 1; i < n; i++)
    {
        cin >> s[i];
        string aux = "";
        for (int j = 0; j < 5; j++)
        {
            if (s[i][j] == s[0][j])
            {
                aux += "*";
                continue;
            }

            if (!appear_letter_in_secret_word[s[i][j]])
                aux += "X";
            else
                aux += "!";
        }

        freq[aux]++;
    }

    int g;
    cin >> g;

    for (int i = 0; i < g; i++)
    {
        string t;
        cin >> t;

        cout << freq[t] << endl;
    }

    return 0;
}