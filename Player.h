#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Player
{
public :
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Player();

	void update(float deltatime);
	void draw(RenderWindow& window);

private :
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

