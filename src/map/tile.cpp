#include "tile.hpp"

Tile::Tile(Types type) : type_(type) {
  switch (type) {
    case Path:
      texture_ = "sprites/sand_tile.png";
      break;
    default:
      texture_ = "sprites/grass_tile_1.png";
  }
}

const Types Tile::GetType() const { return type_; }

const std::string& Tile::GetTexture() const { return texture_; }

std::ostream& operator<<(std::ostream& os, const Tile& tile) {
  os << tile.GetType();
  return os;
};