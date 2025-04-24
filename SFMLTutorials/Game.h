#include <SFML/Graphics.hpp>
#include "Renderer.h"

#pragma once

void Begin(sf::RenderWindow& window);

void Update(float deltaTime);

void Render(Renderer& renderer);