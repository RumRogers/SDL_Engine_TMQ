#ifndef GAME_H
#define GAME_H

#include <SDL_events.h>
#include <unordered_set>

struct SDL_Window;
struct SDL_Renderer;
class ResourceLoader;
class GraphicsManager;
class Scene;

class Game
{
public:
	Game() : 
		m_window(nullptr), m_renderer(nullptr), m_quit(false), m_ev(), m_resourceLoader(nullptr),
		m_currentScene(nullptr), m_graphicsManager(nullptr), m_ticksCounter(0) {}
	~Game();

	bool initialize();
	void gameLoop();
	void cleanUp();
	SDL_Renderer* getRenderer() const;
	ResourceLoader* getResourceLoader() const;
	GraphicsManager* getGraphicsManager() const;

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int TARGET_FRAMERATE;
	static const int FRAME_LOWER_BOUND;
	static const int FRAME_UPPER_BOUND;	

private:
	void getInput();
	void update();
	void render();
	bool loadGame(); // game specific

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event m_ev;
	ResourceLoader* m_resourceLoader;
	GraphicsManager* m_graphicsManager;
	Scene* m_currentScene;
	std::vector<Scene*> m_scenes;
	unsigned int m_ticksCounter;
	bool m_quit;	
};

#endif // !GAME_H

