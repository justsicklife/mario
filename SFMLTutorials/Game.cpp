#include <SFML/Graphics.hpp>
#include "Game.h"

// ���� �׸��� ��ü�̴�
sf::CircleShape circle(2.0f,360u);

void Begin(sf::RenderWindow& window)
{
	// �� �߽��� ������ �������� �����Ѵ�
	circle.setOrigin(sf::Vector2f(circle.getRadius(),circle.getRadius()));;
	// ���� ���� ��������� 
	circle.setFillColor(sf::Color::Yellow);
}

void Update(float deltaTime)
{

}

void Render(sf::RenderWindow& window)
{
	// ȭ�鿡 ���� �׷���
	window.draw(circle);
}
