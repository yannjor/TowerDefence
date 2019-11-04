#include "tile.hpp"

Tile::Tile(Types type) : type_(type) {}
const Types Tile::GetType() const { return type_; }

std::ostream& operator<<(std::ostream& os, const Tile& tile) {
  os << tile.GetType();
  return os;
};