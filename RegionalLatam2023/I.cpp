#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;

    long long n;
    cin >> n;

    vector<long long> freq(26, 0);
    long long inversions = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        freq[c - 'a']++;

        // contar las inversiones sumando la cantidad de ocurrencias de las letras que estan despues de la letra c
        for (int j = c - 'a' + 1; j < 26; j++)
        {
            inversions += freq[j];
        }
    }

    // multiplico la cantidad de inversiones por n ... ya que se repiten n veces la cadena
    inversions *= n;

    // dado s1 y s2 dos strings
    // sea f(s1 + s2) = f(s1) + f(s2) + g(s1, s2)
    // donde f(s) = inversiones que hay en el string s
    // g(s1, s2) = nro de inversiones que pueden ocurrir debido que hay letras en el string s2
    // que son menores (en el orden alfabetico) que las letras en el string s1

    long long g = 0;
    // itero para cada letra del abecedario que este en el string s
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] <= 0) // si es NO es mayor que 0, significa que la letra no aparece en el string s
            continue;

        // le sumo a g la cantidad de letras que son mayores que la letra #i del abecedario
        for (int j = i + 1; j < 26; j++)
            g += freq[i] * freq[j]; // si hay 5 letras 'a' y 3 letras 'd', se tiene que cada letra 'a' es menor que las 3 letras 'd'
    }

    // se mulltiplica g por n * (n - 1) / 2 (la formula de la sumatoria de i = 1 a i = n
    // ya que cada vez que concateno s, se aumenta g en g, 2*g, 3*g, etc...

    // ejemplo: s = "cab"
    // si concateno s con s, se tiene "cabcab"
    // entonces g = 2 + 1 = 3... pues la letra 'a' de la segunda parte es menor que 'c' y 'b' de la primera parte
    // y 'b' de la segunda parte es menor que 'c' de la primera parte

    // si concateno s con s, se tiene "cabcabcab"
    // entonces g = 4 + 2 = 6... pues la letra 'a' de la ultima parte es menor que las 2 letras de 'c' y las 2 letras de 'b'... y 'b' de la ultima parte es menor que las 2 letras de 'c'

    // si concateno s con s, se tiene "cabcabcabcab"
    // entonces g = 6 + 3 = 9... pues la letra 'a' de la ultima parte es menor que las 3 letras de 'c' y las 3 letras de 'b'... y 'b' de la ultima parte es menor que las 3 letras de 'c'

    // y asi voy...

    inversions = ((inversions % MOD) + (((g % MOD) * ((long long)((int)(n * (n - 1) / 2) % MOD))) % MOD)) % MOD;

    cout << inversions << endl;
    return 0;
}