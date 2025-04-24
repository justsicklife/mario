#pragma once

#include <SFML/Graphics.hpp>
// 정렬이 필요없는 맵
#include <unordered_map>

class Resources
{
public :
	static std::unordered_map<std::string, sf::Texture> textures;
};