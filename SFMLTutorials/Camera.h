#pragma once

#include <SFML/Graphics.hpp>

class Camera 
{
public :
	Camera(float zoomLevel = 5.0f);
	sf::View GetView(sf::Vector2u windowSize);

	float zoomLevel;
	// Vector2f ��� position ��ü ����
	sf::Vector2f position;
};