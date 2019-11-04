#pragma once
#include <SFML/Graphics.hpp>
#include "../map/map.hpp"

class Game {
 public:
  Game();
  void Run();
  void DrawAll();
  void DrawMap();

 private:
  Map map_;
  sf::RenderWindow window_;
  sf::View view_;
};