class Track {
    string Name;
    int Length;
};

class Vinyl {
    string Artist;
    Genre Genre;
    int Length;
    Track[] Tracks;
};

class Collection {
    Genre CollectionGenre;
    Vinyl[] Records;
};

class TrackSelector {
    std::queue<track> Queue;
    std::stack<track> Played;
    public:
    void Search(string TrackName, string ArtistName);
    void AddToQueue();
};

class Jukebox {
    Track CurrentTrack;

    public:
    void PlayTrack();   // Adds to queue if current track is not null.

};
