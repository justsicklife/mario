#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Renderer.h"
#include "Resources.h"
#include <filesystem>
#include "Map.h"

Map map;
// 함수 선언 으로 오해할수 있지만 이것은 생성자다 
// 왜냐하면 매게변수가 있기떄문에 함수선언으로 볼수없다
// zoomLevel 초기화 시키는 생성자
Camera camera(320.0f);

void Begin(sf::RenderWindow& window)
{
	// 디렉토리 안에 있는 모든 파일을 하나씩 순회
	for (auto& file : 
		std::filesystem::directory_iterator("./resources/textures/")) {
		if (file.is_regular_file() &&
			(file.path().extension() == ".png" || 
			file.path().extension() == ".jpg")) 
		{
			// 
			Resources::textures[
				file.path().filename().string()]
				.loadFromFile(file.path().string());

		}
	}

	map.CreateCheckerboard(10, 10);
	camera.position = sf::Vector2f(160.0f, 160.0f);

}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	map.Draw(renderer);
}
