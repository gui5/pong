#ifndef __PLAYER__
#define __PLAYER_

#include <SFML/Graphics.hpp>
#include <array>
#include <map>

enum class PlayerSide { left, right };
enum class PaddleMoveDiretion { UP = -1, DOWN = 1 };

struct Paddle {

  const float y_width_center = 128 / 2;
  const float x_width = 8;
  const float y_width = 128;
  float y_position;
  float x_position;
  float y_speed;
  bool move;

  sf::RectangleShape shape;

  Paddle(float x_position)
      : x_position(x_position), y_position(y_position),
        shape({x_width, y_width}), move(false) {

    y_position = 384 - y_width_center;
    shape.setPosition({x_position, y_position});
    shape.setFillColor(sf::Color::White);
  }

  void set_position_y(float pos) { shape.setPosition({x_position, pos}); }

  operator sf::RectangleShape &(void) { return shape; }
};

struct Player {
  int id;
  PlayerSide side;
  Paddle paddle;

  Player(int id, PlayerSide side)
      : id(id), side(side), paddle(side == PlayerSide::left ? 8 : 1004) {}

  void set_paddle_y_position(float pos) { paddle.set_position_y(pos); }

  ~Player(void) = default;

  operator sf::RectangleShape &(void) { return paddle; }
};

#endif