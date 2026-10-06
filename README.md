Algorithm:

1. Start.
2. Create a circular linked list node containing the song name.
3. Add songs to the playlist.
4. Connect the last node back to the first node.
5. Display the songs starting from the first song.
6. After reaching the last song, move back to the first song.
7. Repeat the playlist for the required number of loops.
8. Stop.


Flowchart:
       ┌───────────┐
       │   START   │
       └─────┬─────┘
             ↓
   ┌───────────────────┐
   │ Create playlist   │
   │ using linked list │
   └─────────┬─────────┘
             ↓
   ┌───────────────────┐
   │ Add song to       │
   │ circular list     │
   └─────────┬─────────┘
             ↓
   ┌───────────────────┐
   │ Display current   │
   │ song              │
   └─────────┬─────────┘
             ↓
   ┌───────────────────┐
   │ Is last song      │
   │ reached?          │
   └──────┬───────┬────┘
          │No     │Yes
          ↓       ↓
   ┌──────────┐  ┌───────────────┐
   │ Next song│  │ Go to first   │
   └────┬─────┘  │ song          │
        │        └───────┬───────┘
        └────────┬───────┘
                 ↓
       ┌──────────────────┐
       │ Repeat playlist  │
       └────────┬─────────┘
                ↓
           ┌─────────┐
           │   STOP  │
           └─────────┘


output:

Music Loop System
Loop 1:
Playing: Song A
Playing: Song B
Playing: Song C
Playing: Song D

Loop 2:
Playing: Song A
Playing: Song B
Playing: Song C
Playing: Song D

Loop 3:
Playing: Song A
Playing: Song B
Playing: Song C
Playing: Song D
