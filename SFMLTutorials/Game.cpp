#include <SFML/Graphics.hpp>
#include "Game.h"

// ���� �׸��� ��ü�̴�
sf::CircleShape circle(300.0f);

void Begin(sf::RenderWindow& window)
{
	// �� �߽��� ������ �������� �����Ѵ�
	circle.setOrigin(sf::Vector2f(circle.getRadius(),circle.getRadius()));
	// ���� ��ġ�� ������ �߽����� �����
	circle.setPosition((sf::Vector2f)window.getSize() / 2.0f);
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
