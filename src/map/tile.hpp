class Tile {
public:
    Tile(): occupied_(false) { }
    bool IsOccupued() { return occupied_; }


private:
    bool occupied_;
};