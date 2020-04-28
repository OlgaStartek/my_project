#include <iostream>

class Game {
  public:
    static void Start();
  private:
    enum GameState {
        Uninitialized,
        Pause,
        Playing,
        Exiting
    };
  inline static GameState _gameState = Uninitialized;
};

void Game::Start() {
    if(_gameState != Game::Uninitialized) return;
    std::cout << "Init ...\n";
    _gameState = Game::Playing;
}

int main()
{
    Game::Start();
    return 0;
}
