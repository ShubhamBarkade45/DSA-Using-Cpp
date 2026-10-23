#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of metro stations: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter number of direct connections: ";
    cin >> edges;

    cout << "Enter connections using station numbers (1 to "
         << n << "):\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adj[u - 1][v - 1] = 1;
            adj[v - 1][u - 1] = 1;
        } else {
            cout << "Invalid station number!\n";
            i--;
        }
    }

    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    int station;
    cout << "\nEnter station number to find connections: ";
    cin >> station;

    if (station < 1 || station > n) {
        cout << "Invalid station number!\n";
    } else {
        cout << "Stations directly connected to station "
             << station << ": ";

        bool found = false;

        for (int j = 0; j < n; j++) {
            if (adj[station - 1][j] == 1) {
                cout << j + 1 << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "No direct connections";
        }

        cout << endl;
    }

    return 0;
}
