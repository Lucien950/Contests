#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int monsterCount;
    cin >> monsterCount;
    int hp[monsterCount];
    for (int i = 0; i < monsterCount; i++)
    {
        cin >> hp[i];
    }
    int requiredToKillL[monsterCount], requiredToKillR[monsterCount];
    for (int i = 0; i < monsterCount; i++)
    {
        requiredToKillL[i] = hp[i] + (monsterCount - i);
        requiredToKillR[i] = hp[i] + i;
    }

    cout << max(*std::max_element(requiredToKillL, requiredToKillL + monsterCount),
                *std::max_element(requiredToKillR, requiredToKillR + monsterCount)) << endl;
}
