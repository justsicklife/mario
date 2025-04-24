#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Renderer.h"
#include "Resources.h"
#include <filesystem>

void Begin(sf::RenderWindow& window)
{
	// ���丮 �ȿ� �ִ� ��� ������ �ϳ��� ��ȸ
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

}

void Update(float deltaTime)
{

}

void Render(Renderer& renderer)
{
	
	renderer.Draw(Resources::textures["idle.png"], sf::Vector2f(), sf::Vector2f(2, 2));
}
