#include "Camera.h"

Camera::Camera(float zoomLevel) : zoomLevel(zoomLevel)
{
}

sf::View Camera::GetView(sf::Vector2u windowSize)
{
	// 종횡비를 계산
	float aspect = (float)windowSize.x / (float)windowSize.y;
	
	sf::Vector2f size{};
	
	if (aspect < 1.0f)
		// 세로가 더 길다면(aspect < 1.0), 너비를 zoomLevel, 높이는 그에 맞게 조절.
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	else
		// 가로가 더 길다면(aspect >= 1.0), 높이를 zoomLevel, 너비는 그에 맞게 조절.
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

	return sf::View(sf::Vector2f(0,0),size);
}
