#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Camera.h"

#pragma once

extern Camera camera;

void Begin(sf::RenderWindow& window);

void Update(float deltaTime);

void Render(Renderer& renderer);