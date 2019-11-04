#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "tile.hpp"

class Map {
 public:
  Map(const std::string& filename);
  const int GetWidth() const;
  const int GetHeight() const;
  const std::vector<std::vector<Tile>> GetTiles() const;
  const Tile& operator()(int x, int y) const;

 private:
  std::vector<std::vector<Tile>> tiles_;
};

std::ostream& operator<<(std::ostream& os, const Map& map);