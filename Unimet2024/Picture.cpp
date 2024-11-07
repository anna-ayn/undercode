
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int lines, int arr[], long long maxLength)
{
    long long low = 0, high = maxLength;
    long long ans = high;

    // binary search
    while (low <= high)
    {
        long long mid = (low + high) / 2;

        bool flag = true;
        long long current = mid + 1; // probar con mid + 1 como maxima longitud de letras en cada linea
        int currentLines = lines;

        // itero para cada elemento del arreglo
        for (int i = 0; i < n; i++)
        {
            if (current < arr[i] + 1)
            {
                currentLines--;
                current = mid + 1;
                // si tampoco cabe en la siguiente linea, entonces no es posible usar mid como respuesta
                if (current < arr[i] + 1)
                {
                    flag = false;
                    break;
                }
            }
            current -= (long long)arr[i] + 1; // resto la longitud del nombre junto con el espacio entre palabras
            if (!currentLines)
            {
                flag = false;
                break;
            }
        }

        // ignora la mitad izquierda si todos los nombres no caben usando mid
        if (!flag)
            low = mid + 1;

        // ignora la mitad derecha si todos los nombres caben usando mid
        else
        {
            ans = min(ans, mid); // actualizo la respuesta
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    long long maxLength = 0; // aca almaceno la suma de todas las letras de cada nombre + el espacio entre cada nombre
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxLength += (long long)arr[i] + 1;
    }
    maxLength--; // restar el espacio del ultimo nombre

    cout << solve(n, k, arr, maxLength) << endl;
    return 0;
}
