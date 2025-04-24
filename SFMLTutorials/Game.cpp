#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Renderer.h"
#include "Resources.h"
#include <filesystem>
#include "Map.h"

Map map;
// �Լ� ���� ���� �����Ҽ� ������ �̰��� �����ڴ� 
// �ֳ��ϸ� �ŰԺ����� �ֱ⋚���� �Լ��������� ��������
// zoomLevel �ʱ�ȭ ��Ű�� ������
Camera camera(320.0f);

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
