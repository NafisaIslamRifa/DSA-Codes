
/*#include <iostream>
#include <vector>

using namespace std;

vector<int> findGasStationsToStop(int m, int d, vector<int>& gasStations) {
    vector<int> gasStationsToStop;
    int current_position = 0;
    int num_stops = 0;

    for (int i = 0; i < gasStations.size(); ++i) {
        if (gasStations[i] - current_position > m) {
            // We can't reach the next gas station, so fill up at the previous station.
            gasStationsToStop.push_back(i - 1);
            current_position = gasStations[i - 1];
            num_stops++;
        }
    }

    return gasStationsToStop;
}

int main() {
    int m, d;
    cout << "Enter the gas tank capacity (m): ";
    cin >> m;

    cout << "Enter the total distance (d): ";
    cin >> d;

    int num_gas_stations;
    cout << "Enter the number of gas stations: ";
    cin >> num_gas_stations;

    vector<int> gasStations;
    int station;

    cout << "Enter the distances of gas stations (sorted in ascending order):\n";
    for (int i = 0; i < num_gas_stations; ++i) {
        cin >> station;
        gasStations.push_back(station);
    }

    gasStations.push_back(d); // Adding the total distance as the last gas station

    vector<int> gasStationsToStop = findGasStationsToStop(m, d, gasStations);

    // Output
    for (int i = 0; i < gasStationsToStop.size(); ++i) {
        cout << "Stop at gas station " << gasStationsToStop[i] + 1 << " (" << gasStations[gasStationsToStop[i]] << " miles)\n";
    }

    return 0;
}*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> findGasStationsToStop(int m, int d, vector<int>& gasStations) {
    vector<int> gasStationsToStop;
    int current_position = 0;
    int num_stops = 0;

    for (int i = 0; i < gasStations.size(); ++i) {
        if (gasStations[i] - current_position > m) {
            // We can't reach the next gas station, so fill up at the previous station.
            gasStationsToStop.push_back(i - 1);
            current_position = gasStations[i - 1];
            num_stops++;
        }
    }

    // Check if we can reach the destination from the last gas station
    if (d - current_position > m) {
        gasStationsToStop.empty(); // Clear the gas stations to stop as we can't reach the destination
    }

    return gasStationsToStop;
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
    int station;

    cout << "Enter the distances of gas stations (sorted in ascending order):\n";
    for (int i = 0; i < num_gas_stations; ++i) {
        cin >> station;
        gasStations.push_back(station);
    }

    gasStations.push_back(d); // Adding the total distance as the last gas station

    vector<int> gasStationsToStop = findGasStationsToStop(m, d, gasStations);

    // Output
    if (gasStationsToStop.empty()) {
        cout << "Can't reach destination." << endl;
    } else {
        for (int i = 0; i < gasStationsToStop.size(); ++i) {
            cout << "Stop at gas station " << gasStationsToStop[i] + 1 << " (" << gasStations[gasStationsToStop[i]] << " miles)\n";
        }
    }

    return 0;
}

