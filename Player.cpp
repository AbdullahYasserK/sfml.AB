#include "Player.h"

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;    // we will start at row 0
	faceRight = true;

	body.setSize(Vector2f(100.0f, 100.0f));
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
}


Player::~Player()
{
}

void Player::update(float deltatime)
{
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A))
		movement.x -= speed * deltatime;

		
	if (Keyboard::isKeyPressed(Keyboard::D))
		movement.x += speed * deltatime;


	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
		faceRight = true;
		else
			faceRight = false;
		
		
	}
	animation.update(row, deltatime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}

void Player::draw(RenderWindow& window)
{

	window.draw(body);
}
