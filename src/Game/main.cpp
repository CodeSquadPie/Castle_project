#include <SFML/Graphics.hpp>
#include "lua.hpp"

int main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 2. kychka-pc.ru");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	luaL_loadfile(L, "testHello.lua");
	lua_call(L, 0, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}