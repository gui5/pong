

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <ball.hpp>
#include <field.hpp>
#include <player.hpp>

int main(int ac, char **av) {

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Pong",
                          sf::Style::Default, settings);
  window.setKeyRepeatEnabled(false);

  //  sf::Clock clock;
  Player p1(1, PlayerSide::left);
  Player p2(2, PlayerSide::right);

  Field field;

  Ball ball;

  window.setVerticalSyncEnabled(true);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::MouseMoved:
        p1.set_paddle_y_position((float)sf::Mouse::getPosition(window).y -
                                 (128 / 2));
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
          window.close();
          break;

        default:
          break;
        }
      }

      window.clear();
      window.draw(p1);
      window.draw(p2);
      window.draw(ball);
      for (const auto &fo : field.field_objects) {
        window.draw(fo);
      }
      window.display();
    }
  }

  return 0;
}
