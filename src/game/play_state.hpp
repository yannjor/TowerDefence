#pragma once
#include <SFML/Graphics.hpp>
#include "../gui/button.hpp"
#include "../map/map.hpp"
#include "game_state.hpp"

class PlayState : public GameState {
 public:
  PlayState(Game* game);
  virtual void Draw();
  virtual void HandleInput();
  Map map;
  int GetTileSize() const;
  void InitGUI();

 private:
  sf::View view_;
  sf::Sprite background_;
  sf::Font font_;
  std::map<std::string, Button> buttons_;
};