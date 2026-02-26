// "Copyright [2023] <Michael Jreij>"  [legal/copyright]
#include "hexa.hpp"
#include <cmath>

const float angle = 2 * M_PI / 6;

void drawBase(sf::RenderWindow& window,
sf::Vector2f origin, float length, int sides, sf::Color color) {
    sf::ConvexShape hexagon(sides);
    for (int i = 0; i < 6; i++) {
        hexagon.setPoint(i, sf::Vector2f(origin.x + length * cos(i * angle),
                                          origin.y + length * sin(i * angle)));
        hexagon.setFillColor(color);
    }
    window.draw(hexagon);
}

void drawHelper(sf::RenderWindow& window,
sf::Vector2f baseOrigin, float baseLength, int rep) {
    if (rep == 0) {
        drawBase(window, baseOrigin, baseLength, 6, sf::Color::Red);
    } else {
        float newLength = baseLength / 3;
        for (int i = 0; i < 6; i++) {
            sf::Vector2f newOrigin(baseOrigin.x + baseLength
            / 1.5 * cos(i * angle),
                                   baseOrigin.y + baseLength /
                                   1.5 * sin(i * angle));
            drawHelper(window, newOrigin, newLength, rep - 1);
        }
        if (rep % 3 == 0) {
            drawBase(window, baseOrigin, newLength, 6, sf::Color::Green);
        } else if (rep % 3 == 1) {
            drawBase(window, baseOrigin, newLength, 6, sf::Color::Blue);
        } else {
            drawBase(window, baseOrigin, newLength, 6, sf::Color::Red);
        }
    }
}
// ./hexa 200.0 5
