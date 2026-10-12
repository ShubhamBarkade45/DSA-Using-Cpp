#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

struct Node {
    string song;
    Node* next;
};

class MusicLoop {
private:
    Node* last;

public:
    MusicLoop() {
        last = nullptr;
    }

    void addSong(string name) {
        Node* newNode = new Node;
        newNode->song = name;

        if (last == nullptr) {
            last = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void play(int loops) {
        if (last == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (loops <= 0) {
            cout << "Invalid number of loops." << endl;
            return;
        }

        vector<string> songs;
        Node* first = last->next;
        Node* current = first;

        do {
            songs.push_back(current->song);
            current = current->next;
        } while (current != first);

        mt19937 g(
            static_cast<unsigned>(
                chrono::steady_clock::now()
                    .time_since_epoch().count()
            )
        );

        for (int i = 1; i <= loops; i++) {
            shuffle(songs.begin(), songs.end(), g);

            cout << "\nLoop " << i << ":" << endl;

            for (int j = 0; j < static_cast<int>(songs.size()); j++) {
                cout << "Playing: " << songs[j] << endl;
            }
        }
    }

    ~MusicLoop() {
        if (last == nullptr) {
            return;
        }

        Node* first = last->next;
        last->next = nullptr;

        Node* current = first;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        last = nullptr;
    }
};

int main() {
    MusicLoop playlist;

    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.addSong("Song D");

    cout << "Music Loop System" << endl;

    playlist.play(3);
    return 0;
}
