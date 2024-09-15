#include <iostream>
#include <vector>

using namespace std;

bool findGasStationsToStop(int m, int d, vector<int>& gasStations, vector<int>& gasStationsToStop) {
    int current_position = 0;

    for (int i = 0; i < gasStations.size(); ++i) {
        if (gasStations[i] - current_position > m) {
            // We can't reach the next gas station, so fill up at the previous station.
            gasStationsToStop.push_back(i - 1);
            current_position = gasStations[i - 1];
        }
    }

    // Check if we can reach the destination from the last gas station
    if (d - current_position > m) {
        return false;
    }

    return true;
}

int main() {
    int m, d, num_gas_stations;
    cout << "Enter the gas tank capacity (m): ";
    cin >> m;

    cout << "Enter the total distance (d): ";
    cin >> d;

    cout << "Enter the number of gas stations: ";
    cin >> num_gas_stations;

    vector<int> gasStations;
    vector<int> gasStationsToStop;
    int station;

    cout << "Enter the distances of gas stations (sorted in ascending order):\n";
    for (int i = 0; i < num_gas_stations; ++i) {
        cin >> station;
        gasStations.push_back(station);
    }

  //  gasStations.push_back(d); // Adding the total distance as the last gas station

    bool canReachDestination = findGasStationsToStop(m, d, gasStations, gasStationsToStop);

    // Output
    if (canReachDestination) {
        if (gasStationsToStop.empty()) {
            cout << "Can reach the destination without stops." << endl;
        } else {
            for (int i = 0; i < gasStationsToStop.size(); ++i) {
                cout << "Stop at gas station " << gasStationsToStop[i] + 1 << " (" << gasStations[gasStationsToStop[i]] << " miles)\n";
            }
        }
    } else {
        cout << "Can't reach destination." << endl;
    }

    return 0;
}
