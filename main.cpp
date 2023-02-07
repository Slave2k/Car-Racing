#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Road.h"
#include "car.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode
(WINDOW_WIDTH,WINDOW_HEIGHT),
	WINDOW_TITLE,
	Style::Titlebar | Style:: Close);
	window.setPosition (Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1,grass2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "water.jpg",0.f);
	roadLayerInit(grass2, Vector2f{ 0.f, -WINDOW_HEIGHT }, "water.jpg",0.f);

	RoadLayer sand1,sand2;
	roadLayerInit(sand1, Vector2f{ 50.f,0.f }, "sand.png",50.f);
	roadLayerInit(sand2, Vector2f{ 50.f,-WINDOW_HEIGHT }, "sand.png", 50.f);

	RoadLayer road1,road2;
	roadLayerInit(road1, Vector2f{ 100.f,0.f }, "road1.jpg",100.f);
	roadLayerInit(road2, Vector2f{ 100.f,-WINDOW_HEIGHT }, "road1.jpg", 100.f);
	Car car;
	carInit(car, sf::Vector2f{(int)WINDOW_WIDTH/4, WINDOW_HEIGHT - CAR_HEIGHT}, "car.png");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//Update
		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(sand1);
		roadLayerUpdate(sand2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		carUpdate(car);
		// Отрисовка окна
		window.clear();
		roadLayerDraw(window, grass1);
		roadLayerDraw(window, grass2);
		roadLayerDraw(window, sand1);
		roadLayerDraw(window, sand2);
		roadLayerDraw(window, road1);
		roadLayerDraw(window, road2);
		carDraw(window, car);
		window.display();
		
	}

	return 0;
}