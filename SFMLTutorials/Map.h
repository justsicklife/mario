#pragma once

#include <vector>
#include "Renderer.h"

class Map
{
public:
	Map(float cellSize = 16.0f);
	void CreateCheckerboard(size_t width,size_t height);
	void Draw(Renderer& renderer);

	std::vector<std::vector<int>> grid;
	float cellSize;
};

