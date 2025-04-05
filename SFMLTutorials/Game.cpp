#include <SFML/Graphics.hpp>
#include "Game.h"

// 원을 그리는 객체이다
sf::CircleShape circle(2.0f,360u);

void Begin(sf::RenderWindow& window)
{
	// 원 중심을 도형을 원점으로 설정한다
	circle.setOrigin(sf::Vector2f(circle.getRadius(),circle.getRadius()));;
	// 원의 색을 노란색으로 
	circle.setFillColor(sf::Color::Yellow);
}

void Update(float deltaTime)
{

}

void Render(sf::RenderWindow& window)
{
	// 화면에 원을 그려줌
	window.draw(circle);
}
