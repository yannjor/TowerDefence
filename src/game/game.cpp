#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game() : map_(Map("out/map.txt")), window_(), view_() {
  window_.create(sf::VideoMode(800, 600), "Tower Defence");
}

void Game::Run() {
  window_.setView(view_);
  // run the program as long as the window is open
  while (window_.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window_.close();
      if (event.type == sf::Event::Resized) {
        view_.reset(sf::FloatRect(0, 0, event.size.width, event.size.height));
        window_.setView(view_);
      }
    }
    window_.clear();
    DrawAll();
    window_.display();
  }
}

void Game::DrawAll() { DrawMap(); }

void Game::DrawMap() {
  auto window_size = window_.getSize();
  int tile_size_x = window_size.x / map_.GetWidth();
  int tile_size_y = window_size.y / map_.GetHeight();
  int tile_size = std::min(tile_size_x, tile_size_y);

  sf::RectangleShape rect;
  rect.setSize(sf::Vector2f(tile_size, tile_size));

  for (int y = 0; y < map_.GetHeight(); y++) {
    for (int x = 0; x < map_.GetWidth(); x++) {
      Tile tile = map_(x, y);
      rect.setPosition(x * tile_size, y * tile_size);
      switch (tile.GetType()) {
        case Empty:
          rect.setFillColor(sf::Color(0, 255, 0, 255));
          break;
        case Path:
          rect.setFillColor(sf::Color(255, 255, 0, 255));
          break;
        default:
          rect.setFillColor(sf::Color(255, 0, 0, 255));
          break;
      }
      window_.draw(rect);
    }
  }
}