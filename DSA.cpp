#include <iostream>
#include <string>
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
        } 
        else {
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

        Node* current = last->next;  // First song

        for (int i = 1; i <= loops; i++) {
            cout << "\nLoop " << i << ":" << endl;

            do {
                cout << "Playing: " << current->song << endl;
                current = current->next;
            } while (current != last->next);
        }
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