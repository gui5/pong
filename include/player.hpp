#ifndef __PLAYER__
#define __PLAYER_

#include <SFML/Graphics.hpp>
#include <array>
#include <map>

enum class PlayerSide { left, right };
enum class PaddleMoveDiretion { UP = -1, DOWN = 1 };

struct Player {
  int id;
  PlayerSide side;
  const float position_x;
  float position_y;
  float speed;
  sf::RectangleShape paddle;

  Player(int id, PlayerSide side)
      : id(id), side(side), paddle({16, 128}),
        position_x(side == PlayerSide::left ? 4 : 1004), speed(2048) {

    position_y = 384 - (128 / 2);
    paddle.setPosition({position_x, position_y});
    paddle.setFillColor(sf::Color::White);
  }

  void update_position(sf::Time &&time, PaddleMoveDiretion direction) {
    float delta_y = (int)direction * (speed * time.asSeconds());
    paddle.move({0.0f, delta_y});
  }

  ~Player(void) = default;
};

#endif