#include <SFML/Graphics.hpp>
#include "Player.h"


using namespace sf;
using namespace std;



int main()
{
	RenderWindow window(VideoMode(600, 600), "icy tower", Style::Close | Style::Titlebar);
	Texture playertexture;
	playertexture.loadFromFile("harold.png");
	


	Player player (&playertexture, Vector2u(6, 4), 0.3f, 100.0f);

	float deltatime = 0.0f;
		Clock clock;
		
	// makes window stay open unless we close it.
	while (window.isOpen())
	{
		deltatime = clock.restart().asSeconds();


		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				// window is closed if we click on x in titlebar
			case Event::Closed:
				window.close();

				// window is closed if we press escape
				break;
			case Event::KeyPressed:
				if (evnt.key.code == Keyboard::Escape)
					window.close();
				break;

			}
		}
		


		player.update(deltatime);

		window.clear();
		player.draw(window);

			// here we draw our game .


		window.display();

		
	}

			return 0;
}