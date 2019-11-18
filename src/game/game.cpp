#include "game.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>

Game::Game() : map_(Map("out/map.txt")), window_(), view_(), gui_() {
  window_.create(sf::VideoMode(800, 600), "Tower Defence");
  gui_.setWindow(window_);
  auto spawn = map_.GetEnemySpawn();
  enemies_.push_back(Enemy(100, 1, spawn.first + 0.5, spawn.second + 0.5));
  towers_.push_back(Tower(10, 10, 2, 1, 2));
}

void Game::Run() {
  LoadTextures();

  window_.setView(view_);
  window_.setFramerateLimit(60);

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
    Tick();
    window_.display();
  }
}

void Game::Tick() {
  auto path = map_.GetPath();
  auto player_base = map_.GetPlayerBase();
  for (auto it = enemies_.begin(); it != enemies_.end(); it++) {
    if (it->IsAlive()) {
      it->Move(path);
      if (it->GetTile() == player_base) {
        it->SetHp(0);
      }
    }
  }
  FindEnemies();
}

void Game::DrawAll() {
  DrawMap();
  DrawEnemies();
  DrawTowers();
  DrawGui();
}

void Game::DrawMap() {
  int tile_size = GetTileSize();
  sf::Sprite sprite;
  sf::Texture* texture;

  for (int y = 0; y < map_.GetHeight(); y++) {
    for (int x = 0; x < map_.GetWidth(); x++) {
      Tile tile = map_(x, y);
      texture = &textures_.at(tile.GetTexture());
      sprite.setTexture(*texture);
      sprite.setPosition(x * tile_size, y * tile_size);
      sprite.setScale(tile_size / (float)(*texture).getSize().x,
                      tile_size / (float)(*texture).getSize().y);
      window_.draw(sprite);
    }
  }
}

void Game::DrawEnemies() {
  int enemy_size = GetTileSize();
  for (auto it = enemies_.begin(); it != enemies_.end(); it++) {
    if (it->IsAlive()) {
      sf::Sprite sprite;
      sf::Texture* texture = &textures_.at(it->GetTexture());
      sprite.setTexture(*texture);
      sprite.setPosition(
          it->GetPosition().first * enemy_size - enemy_size / 2,
          it->GetPosition().second * enemy_size - enemy_size / 2);
      sprite.setScale(enemy_size / (float)(*texture).getSize().x,
                      enemy_size / (float)(*texture).getSize().y);
      window_.draw(sprite);
    }
  }
}

void Game::DrawTowers() {
  int tower_size = GetTileSize();
  for (auto it = towers_.begin(); it != towers_.end(); it++) {
    sf::Sprite sprite;
    sf::Texture* texture = &textures_.at(it->GetTexture());
    sprite.setTexture(*texture);
    sprite.setPosition(it->GetPosition().first * tower_size,
                       it->GetPosition().second * tower_size);
    sprite.setScale(tower_size / (float)(*texture).getSize().x,
                    tower_size / (float)(*texture).getSize().y);
    window_.draw(sprite);
  }
}

void Game::DrawSidebar() {
  tgui::Grid::Ptr layout = tgui::Grid::create();
  layout->setSize(window_.getSize().x - ((map_.GetWidth() - 1) * GetTileSize()),
                  0.5f * tgui::bindHeight(gui_));
  layout->setPosition((map_.GetWidth() - 1) * GetTileSize(), 0);
  gui_.add(layout);
  sf::Texture* texture = &textures_.at("sprites/basic_tower.png");
  try {
    for (size_t i = 0; i < 2; i++) {
      for (size_t j = 0; j < 2; j++) {
        auto button = tgui::Button::create();
        button->setSize(100, 100);
        // tgui::Texture texturea(*texture, sf::IntRect(0, 0, 0, 0),
        // sf::IntRect(0, 0, 0, 0));

        // button->getRenderer()->setNormalTexture(texturea);

        button->connect("pressed", [&]() { window_.close(); });
        layout->addWidget(button, j, i, tgui::Borders(0, 0, 0, 0));
      }
    }

  } catch (const tgui::Exception& e) {
    std::cerr << "TGUI Exception: " << e.what() << std::endl;
  }
}

void Game::DrawGui() {
  gui_.removeAllWidgets();
  DrawSidebar();
  gui_.draw();
}

void Game::LoadTextures() {
  LoadTexture("sprites/grass_tile_1.png");
  LoadTexture("sprites/sand_tile.png");
  LoadTexture("sprites/basic_enemy.png");
  LoadTexture("sprites/basic_tower.png");
}

void Game::LoadTexture(const std::string texture_name) {
  sf::Texture texture;
  texture.loadFromFile(texture_name);
  texture.setSmooth(true);
  textures_.insert(std::make_pair(texture_name, texture));
}

const int Game::GetTileSize() const {
  auto window_size = window_.getSize();
  int tile_size_x = (window_size.x - 200) / map_.GetWidth();
  int tile_size_y = (window_size.y - 200) / map_.GetHeight();
  return std::min(tile_size_x, tile_size_y);
}

void Game::FindEnemies() {
  auto cur_time = clock_.getElapsedTime().asSeconds();
  float closest_distance = std::numeric_limits<float>::max();
  auto closest_enemy = enemies_.end();
  for (auto& tower : towers_) {
    float range = tower.GetRange();
    auto tower_pos = tower.GetPosition();
    for (auto it = enemies_.begin(); it != enemies_.end(); it++) {
      auto enemy_pos = it->GetPosition();
      float distance = sqrt(pow(tower_pos.first + 0.5 - enemy_pos.first, 2) +
                            pow(tower_pos.second + 0.5 - enemy_pos.second, 2));
      if (distance <= range && distance < closest_distance && it->IsAlive()) {
        closest_enemy = it;
        closest_distance = distance;
      }
    }
    if ((closest_enemy != enemies_.end()) &&
        (cur_time - tower.GetLastAttack() > tower.GetAttSpeed())) {
      tower.SetLastAttack(cur_time);
      tower.Attack(*closest_enemy);
    }
  }
}