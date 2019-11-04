#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game() : map_(Map("map.txt")), window_() {
  window_.create(sf::VideoMode(800, 600), "Tower Defence");
}

void Game::Run() {
  // run the program as long as the window is open
  while (window_.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window_.close();
    }
    window_.clear();
    window_.display();
  }
}