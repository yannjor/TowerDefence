#pragma once
#include <SFML/Graphics.hpp>
#include "../map/map.hpp"

class Game {
 public:
  Game();
  void Run();

 private:
  Map map_;
  sf::RenderWindow window_;
};