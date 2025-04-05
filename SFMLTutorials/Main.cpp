#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	// window ��ü�� �����ϴ� �������ε� 
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1200,900)), "BATTER Mario");

	// deltaClock �̶�� ��ü�� ����
	sf::Clock deltaClock;

	Begin(window);

	// ȭ���� ����������
	while (window.isOpen())
	{	
		// �����Ӱ� �������� ���� �ð�
		float deltaTime = deltaClock.restart().asSeconds();

		// pool �̺�Ʈ�� ��ȯ������ ����
		while (const std::optional event = window.pollEvent())
		{
			// â �ݱ� �ڵ�� 
			if (event->is<sf::Event::Closed>())
			{
				// â����
				window.close();
			}
		}

		Update(deltaTime);

		// ���� ������ �����
		window.clear();
		
		// ȭ�鿡 �׸� ��� ���ϱ�
		Render(window);

		// ���� ���۸� �׸��� �̰��ϸ� ���۸� ȭ�鿡 ��ȯ�Ѵ�
		window.display();
	}
}