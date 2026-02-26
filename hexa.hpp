// "Copyright [2023] <Michael Jreij>"  [legal/copyright]
#pragma once
#include <SFML/Graphics.hpp>

void drawBase(sf::RenderWindow& window,
sf::Vector2f origin, float length, int sides, sf::Color color);
void drawHelper(sf::RenderWindow& window,
sf::Vector2f origin, float length, int rep);
