#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Camera.h"
#include "Renderer.h"

int main() {
	// window 객체를 생성하는 생성자인데 
	sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1200,900)), "BATTER Mario");

	// deltaClock 이라는 객체를 생성
	sf::Clock deltaClock;

	Camera camera;

	sf::Texture texture{};

	sf::Sprite sprite(texture);

	// renderer 에 window,sprite 를 넣는다.
	Renderer renderer(window, sprite);

	Begin(window);

	// 화면이 열려있으면
	while (window.isOpen())
	{	
		// 프레임과 프레임의 간격 시간
		float deltaTime = deltaClock.restart().asSeconds();

		// pool 이벤트가 반환됬을떄 실행
		while (const std::optional event = window.pollEvent())
		{
			// 창 닫기 코드면 
			if (event->is<sf::Event::Closed>())
			{
				// 창닫음
				window.close();
			}
		}

		// 카메라가 바라보는 방향설정
		window.setView(camera.GetView(window.getSize()));

		Update(deltaTime);

		// 이전 프레임 지우기
		window.clear();
		
		// 화면에 그릴 요소 정하기
		Render(renderer);

		// 내부 버퍼를 그리고 이걸하면 버퍼를 화면에 전환한다
		window.display();
	}
}