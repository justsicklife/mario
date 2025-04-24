#include "Camera.h"
#include <iostream>
Camera::Camera(float zoomLevel) : zoomLevel(zoomLevel)
{
}

sf::View Camera::GetView(sf::Vector2u windowSize)
{
	// ��Ⱦ�� ���
	float aspect = (float)windowSize.x / (float)windowSize.y;
	
	std::cout << zoomLevel << std::endl;

	sf::Vector2f size{};
	
	if (aspect < 1.0f)
		// ���ΰ� �� ��ٸ�(aspect < 1.0), �ʺ� zoomLevel, ���̴� �׿� �°� ����.
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	else
		// ���ΰ� �� ��ٸ�(aspect >= 1.0), ���̸� zoomLevel, �ʺ�� �׿� �°� ����.
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

	return sf::View(position,size);
}
