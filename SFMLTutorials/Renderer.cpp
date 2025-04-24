#include "Renderer.h"
#include <vector>

#include <iostream>

Renderer::Renderer(sf::RenderTarget& target,sf::Sprite sprite)
	: target(target), sprite(sprite)
{
}

void Renderer::Draw(
	const sf::Texture& texture,
	const sf::Vector2f& position, // 좌표
	const sf::Vector2f& size // 크기
) {
	sprite.setTexture(texture,true);
	sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.0f);
	sprite.setPosition(position);
	sprite.setScale(sf::Vector2f(
		size.x/texture.getSize().x,
		size.y/texture.getSize().y
	));

	target.draw(sprite);
}