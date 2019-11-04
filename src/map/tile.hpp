#pragma once
#include <iostream>

enum Types { Path, Empty };

class Tile {
 public:
  Tile(Types type = Empty);
  const Types GetType() const;

 private:
  Types type_;
  std::string texture_;
};

std::ostream& operator<<(std::ostream& os, const Tile& tile);
