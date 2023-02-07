#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Car {
	sf::Texture texture;
	sf::Sprite sprite;
	float carSpeedX;
};
void carInit(Car& car, sf::Vector2f pos, std::string fileName)
{
	car.texture.loadFromFile(fileName);
	car.sprite.setTexture(car.texture);
	car.sprite.setPosition(pos);
	car.carSpeedX = 2.f;
}
void carUpdate(Car& car) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		car.carSpeedX = -CAR_SPEED_X;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		car.carSpeedX = CAR_SPEED_X;
	car.sprite.move(car.carSpeedX, 0.f);
	car.carSpeedX = 0.f;
}
void carDraw(sf::RenderWindow& window, const Car& car) {
	window.draw(car.sprite);
}
