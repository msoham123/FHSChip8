class Display {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public: 
	void initDisplay(bool* displayBools);
	void updateDisplay(bool* displayBools);
};