#include "Game.h"
#include "Utils.h"
#include "Scene.h"
#include "ResourceLoader.h"
#include "GraphicsManager.h"
#include "MainScene.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int Game::SCREEN_WIDTH = 1024;
const int Game::SCREEN_HEIGHT = 768;
const int Game::TARGET_FRAMERATE = 60;
const int Game::FRAME_LOWER_BOUND = 1000 / Game::TARGET_FRAMERATE;
const int Game::FRAME_UPPER_BOUND = 3 * Game::FRAME_LOWER_BOUND;


Game::~Game()
{
	delete m_resourceLoader;
	for (Scene* scene : m_scenes)
	{
		delete scene;
	}
}

bool Game::initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Utils::printSDLError("Could not initialize SDL!");
		return false;
	}

	m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!m_window)
	{
		Utils::printSDLError("Could not create SDL Window!");
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer)
	{
		Utils::printSDLError("Could not create SDL Renderer!");
		return false;
	}
	
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
	{
		Utils::printSDLError("Could not initialize SDL_image!");
		return false;
	}

	m_resourceLoader = new ResourceLoader(m_renderer);
	m_graphicsManager = new GraphicsManager(m_renderer);

	return loadGame();
}

void Game::gameLoop()
{
	m_ticksCounter = SDL_GetTicks();
	while (!m_quit)
	{
		getInput();
		update();
		render();
	}
}

void Game::cleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);	
	SDL_Quit();
}

void Game::getInput()
{
	while (SDL_PollEvent(&m_ev))
	{
		switch (m_ev.type)
		{
		case SDL_QUIT:
			m_quit = true;
			break;
		case SDL_KEYDOWN:
			switch (m_ev.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					m_quit = true;
				default:
					break;
			}
			break;
		}
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
	SDL_RenderClear(m_renderer); // clear renderer with draw color
	m_currentScene->render();
	SDL_RenderPresent(m_renderer); // swap back buffer and front buffer
}

void Game::update()
{
	double deltaTime;
	unsigned int minWait = m_ticksCounter + FRAME_LOWER_BOUND;

	while (!SDL_TICKS_PASSED(SDL_GetTicks(), minWait)) // framerate capping
	{
		//SDL_Log("Too fast! Waiting for %d milliseconds to pass...\n", FRAME_LOWER_BOUND);
	} 

	deltaTime = SDL_GetTicks() - m_ticksCounter;
	
	if (deltaTime > FRAME_UPPER_BOUND) // in case of slow machine or pause
	{
		deltaTime = FRAME_UPPER_BOUND;
		SDL_Log("Too slow! deltaTime is now %d", FRAME_UPPER_BOUND);
	}

	deltaTime /= 1000;
	//SDL_Log("deltaTime: %f\n", deltaTime);

	m_ticksCounter = SDL_GetTicks();

	m_currentScene->update(deltaTime);
}

SDL_Renderer* Game::getRenderer() const
{
	return m_renderer;
}

ResourceLoader* Game::getResourceLoader() const
{
	return m_resourceLoader;
}

GraphicsManager* Game::getGraphicsManager() const
{
	return m_graphicsManager;
}

bool Game::loadGame()
{
	Scene* s = new MainScene(this);
	m_scenes.emplace_back(s);
	m_currentScene = s;

	return true;	
}

