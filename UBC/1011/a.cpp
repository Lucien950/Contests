#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int friendCount, bottles, mlPerBottle, limes, slicesPerLime, salt, mlPerFriend, saltPerFriend;
    cin >> friendCount >> bottles >> mlPerBottle >> limes >> slicesPerLime >> salt >> mlPerFriend >> saltPerFriend;
    int totalML = bottles * mlPerBottle;
    int totalSlices = limes * slicesPerLime;

    int mlPerToast = mlPerFriend * friendCount;
    int saltPerToast = saltPerFriend * friendCount;
    int slicesPerToast = friendCount;

    int toastsMadeWithMls = totalML / mlPerToast;
    int toastsMadeWithSlices = totalSlices / slicesPerToast;
    int toastsMadeWithSalt = salt / saltPerToast;

    int toastsMade = std::min(toastsMadeWithMls, std::min(toastsMadeWithSlices, toastsMadeWithSalt));
    cout << toastsMade << endl;
}