#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int n;

void displayMatrix() {
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

// A. Add a new station
void addStation() {
    adj.push_back(vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
        adj[i].push_back(0);

    n++;

    cout << "New station number: " << n << endl;

    for (int i = 0; i < n - 1; i++) {
        int connected;

        cout << "Connect station " << n
             << " with station " << i + 1
             << "? (1=Yes, 0=No): ";
        cin >> connected;

        if (connected == 1) {
            adj[n - 1][i] = 1;
            adj[i][n - 1] = 1;
        }
    }

    cout << "Station added successfully.\n";
    displayMatrix();
}

// B. Remove a closed track link
void removeTrack() {
    int u, v;

    cout << "Enter two station numbers: ";
    cin >> u >> v;

    if (u < 1 || u > n || v < 1 ||
        v > n || u == v) {
        cout << "Invalid station numbers!\n";
        return;
    }

    if (adj[u - 1][v - 1] == 0) {
        cout << "Track link does not exist.\n";
        return;
    }

    adj[u - 1][v - 1] = 0;
    adj[v - 1][u - 1] = 0;

    cout << "Track link removed successfully.\n";
    displayMatrix();
}

// C. Display degree of each station
void displayDegree() {
    cout << "\nDegree of each station:\n";

    for (int i = 0; i < n; i++) {
        int degree = 0;

        for (int j = 0; j < n; j++)
            degree += adj[i][j];

        cout << "Station " << i + 1
             << " = " << degree << endl;
    }
}

int main() {
    int edges, choice;

    cout << "Enter number of metro stations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of stations!\n";
        return 0;
    }

    adj.assign(n, vector<int>(n, 0));

    cout << "Enter number of direct connections: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;

        cout << "Enter connected stations: ";
        cin >> u >> v;

        if (u >= 1 && u <= n &&
            v >= 1 && v <= n && u != v) {
            adj[u - 1][v - 1] = 1;
            adj[v - 1][u - 1] = 1;
        } else {
            cout << "Invalid connection! Try again.\n";
            i--;
        }
    }

    do {
        cout << "\n--- Metro Station Menu ---\n";
        cout << "1. Display adjacency matrix\n";
        cout << "2. Add a new station\n";
        cout << "3. Remove a closed track link\n";
        cout << "4. Display degree of each station\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMatrix();
                break;

            case 2:
                addStation();
                break;

            case 3:
                removeTrack();
                break;

            case 4:
                displayDegree();
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
