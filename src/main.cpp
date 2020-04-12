

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <field.hpp>
#include <player.hpp>

int main(int ac, char **av) {

  sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Pong");

  sf::Clock clock;
  Player p1(1, PlayerSide::left);
  Player p2(2, PlayerSide::right);

  Field field;

  window.setVerticalSyncEnabled(true);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        window.close();
        break;

        case sf::Event::MouseMoved:
        p1.paddle.setPosition({0,(float)sf::Mouse::getPosition(window).y});
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
          window.close();
          break;
        case sf::Keyboard::W:
          p2.update_position(clock.getElapsedTime(), PaddleMoveDiretion::UP);
          break;
        case sf::Keyboard::S:
          p2.update_position(clock.getElapsedTime(), PaddleMoveDiretion::DOWN);
          break;
        default:
          break;
        }

      default:
        break;
      }
    }

    clock.restart();
    window.clear();
    window.draw(p1.paddle);
    window.draw(p2.paddle);
    for (const auto &fo : field.field_objects) {
      window.draw(fo);
    }
    window.display();
  }

  return 0;
}