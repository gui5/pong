#ifndef __BALL__
#define __BALL__

#include <SFML/Graphics.hpp>

struct Ball {
  float speed;
  float posision_x;
  float position_y;
  sf::CircleShape shape;

  Ball(void) : shape(32) {
    shape.setFillColor(sf::Color::Yellow);

    shape.setPosition({400, 200});
  }

  operator sf::Drawable &(void) { return shape; }
};

#endif
