#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"
#include "Renderer.h"

int main() {
	// window ��ü�� �����ϴ� �������ε� 
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1200,900)), "BATTER Mario");

	// deltaClock �̶�� ��ü�� ����
	sf::Clock deltaClock;

	Camera camera;

	sf::Texture texture{};

	sf::Sprite sprite(texture);

	// renderer �� window,sprite �� �ִ´�.
	Renderer renderer(window, sprite);

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

		// ī�޶� �ٶ󺸴� ���⼳��
		window.setView(camera.GetView(window.getSize()));

		Update(deltaTime);

		// ���� ������ �����
		window.clear();
		
		// ȭ�鿡 �׸� ��� ���ϱ�
		Render(renderer);

		// ���� ���۸� �׸��� �̰��ϸ� ���۸� ȭ�鿡 ��ȯ�Ѵ�
		window.display();
	}
}