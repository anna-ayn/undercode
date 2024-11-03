
#include <bits/stdc++.h>

using namespace std;

map<string, int> power = {
    {"Shadow", 6}, {"Gale", 5}, {"Ranger", 4}, {"Anvil", 7}, {"Vexia", 3}, {"Guardian", 8}, {"Thunderheart", 6}, {"Frostwhisper", 2}, {"Voidclaw", 3}, {"Ironwood", 3}, {"Zenith", 4}, {"Seraphina", 1}};

int main()
{
    int rounds = 3, totalScore = 0, totalP1 = 0, totalP2 = 0;

    // para cada ronda (left, center and right location)
    for (int i = 0; i < rounds; i++)
    {
        vector<vector<pair<string, int>>> cards(2);
        // para cada jugador leo sus cartas
        for (int j = 0; j < 2; j++)
        {
            int n;
            cin >> n;
            for (int k = 0; k < n; k++)
            {
                string name_card;
                cin >> name_card;

                cards[j].push_back(make_pair(name_card, power[name_card]));
            }
        }

        vector<int> scores(2);
        // calculo la puntuacion de cada jugador en la ronda
        for (int j = 0; j < 2; j++)
        {
            // para cada carta
            for (int k = 0; k < cards[j].size(); k++)
            {
                // le sumo el poder de la carta
                scores[j] += cards[j][k].second;

                // si el jugador tiene la carta "Thunderheart" y tiene 4 cartas o mas, se le suma de nuevo el poder de la carta (duplica su poder)
                if (cards[j][k].first == "Thunderheart" && cards[j].size() >= 4)
                    scores[j] += cards[j][k].second;

                // si el jugador tiene la carta "Zenith" y es la segunda ronda, se le suma 5 puntos
                if (cards[j][k].first == "Zenith" && i == 1)
                    scores[j] += 5;

                // si el jugador tiene la carta "Seraphina", se le suma 1 punto por cada carta que tenga (excepto la carta actual)
                if (cards[j][k].first == "Seraphina")
                    scores[j] += (cards[j].size() - 1);
            }
        }

        // determina el ganador de la ronda
        if (scores[0] > scores[1])
            totalScore += 1; // si el totalScore es positivo, el jugador 1 gana
        else if (scores[0] < scores[1])
            totalScore -= 1; // si el totalScore es negativo, el jugador 2 gana

        totalP1 += scores[0];
        totalP2 += scores[1];
    }

    if (totalScore > 0 || totalScore == 0 && totalP1 > totalP2)
        cout
            << "Player 1" << endl;
    else if (totalScore < 0 || totalScore == 0 && totalP1 < totalP2)
        cout << "Player 2" << endl;
    else
        cout << "Tie" << endl;

    return 0;
}
