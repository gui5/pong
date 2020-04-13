#ifndef __FIELD__
#define __FIELD__

#include <SFML/Graphics.hpp>
#include <array>
struct Field {
  enum { NET, P1_SCORE, P2_SCORE, UP_LINE, BOTTON_LINE };
  std::array<sf::RectangleShape, 5> field_objects;
  float up_line_position;
  float bot_line_position;

  Field(void) {
    auto &net = field_objects[NET];
    auto &p1_score = field_objects[P1_SCORE];
    auto &p2_score = field_objects[P2_SCORE];
    auto &up_line = field_objects[UP_LINE];
    auto &botton_line = field_objects[BOTTON_LINE];

    net.setFillColor(sf::Color(157, 159, 163));
    net.setSize({8, 768});
    net.setPosition(512, 0);

    up_line.setSize({1024, 4});
    up_line.setFillColor(sf::Color(157, 159, 163));
    up_line.setPosition(0, 0);

    botton_line.setSize({1024, 4});
    botton_line.setFillColor(sf::Color(157, 159, 163));
    botton_line.setPosition(0, 764);
  }

  ~Field(void) = default;
};

#endif