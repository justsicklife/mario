#include "Map.h"
#include "Resources.h"

Map::Map(float cellSize)
	: cellSize(cellSize), grid()
{
}

void Map::CreateCheckerboard(size_t width, size_t height)
{
	// 2���� ���� 
	// width ������ŭ ���� �ְ�
	// �� ������ height ������ŭ �� �� �ִ�
	// �ʱⰪ�� ��� 0���� ä��
	grid = std::vector(width,std::vector(height,0));
	
	int last = 0;
	
	for (auto& column : grid)
	{
		for (auto& cell : column)
		{
			// 0 1 0 1 �����Ƽ� grid �� ä��
			cell = !last;
			last = cell;
		}
	}
}

void Map::Draw(Renderer& renderer)
{
	int x = 0;
	for (const auto& column : grid)
	{
		int y = 0; 
		for (const auto& cell : column)
		{
			if (cell)
			{
				renderer.Draw(Resources::textures["brick.png"],
					sf::Vector2f(
						cellSize * x + cellSize / 2.0f,
						cellSize * y + cellSize / 2.0f),
					sf::Vector2f(cellSize, cellSize));
			}
			y++;
		}
		x++;
	}
}