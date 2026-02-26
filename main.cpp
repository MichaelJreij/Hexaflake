// "Copyright [2023] <Michael Jreij>"  [legal/copyright]
#include <iostream>
#include <SFML/Graphics.hpp>
#include "hexa.hpp"

void drawHexagonalPattern(sf::RenderWindow& window, double length, int depth) {
    sf::Vector2f origin(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    drawHelper(window, origin, length, depth);
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw std::invalid_argument("Usage: ./hexa <length> <depth>");
        }

        double length = std::stod(argv[1]);
        int depth = std::stoi(argv[2]);

        sf::RenderWindow window(sf::VideoMode(1000, 1000), "Hexagonal Pattern");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            drawHexagonalPattern(window, length, depth);
            window.display();
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
