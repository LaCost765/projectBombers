Picture bomberMan("Data/bomberman.png", 0, 0, 573, 780, 0, 0);
Picture titleBomberMan("Data/titleBomberman.png", 0, 0, 600, 150, 600, 50);
Picture newGameButton("Data/newGameButton.png", 0, 0, 400, 100, 700, 250);
Picture newGameActiveButton("Data/newGameActiveButton.png", 0, 0, 400, 100, 700, 250);
Picture continueButton("Data/continueButton.png", 0, 0, 400, 100, 700, 450);
Picture continueActiveButton("Data/continueActiveButton.png", 0, 0, 400, 100, 700, 450);
Picture quitButton("Data/quitButton.png", 0, 0, 400, 100, 700, 650);
Picture quitActiveButton("Data/quitActiveButton.png", 0, 0, 400, 100, 700, 650);
Picture background("Data/background.jpg", 0, 0, 1600, 800, 0, 0);
Picture note1("Data/note1.png", 0, 0, 600, 150, 300, 50);
Picture note2("Data/note2.png", 0, 0, 800, 150, 200, 150);
Picture yesButton("Data/yesButton.png", 0, 0, 200, 200, 300, 400);
Picture noButton("Data/noButton.png", 0, 0, 200, 200, 700, 400);
Picture yesActiveButton("Data/yesActiveButton.png", 0, 0, 200, 200, 300, 400);
Picture noActiveButton("Data/noActiveButton.png", 0, 0, 200, 200, 700, 400);
Picture timeInfoHeader("Data/timeHeader.png", 0, 0, 200, 100, 400, 0);
Picture health("Data/health.png", 0, 0, 150, 150, 1050, 0);
Player hero("Data/heroBomb.png", 50, 100, 50.0, 50.0);
Bomba bomba("Data/bomb1.png", 0, 0, 50, 50, 0);
std::list<Enemy*> enemies;
std::list<Enemy*>::iterator enemies_iterator;
StageMap mainMap;
View view;

bool inGame = false;
bool newGameMenu = false;
bool levelInProcess = false;

int stop = 0;

void generateEnemies(int level, std::list<Enemy*> & enemies, StageMap map);
void updateEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, float time);
void moveEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, float time, StageMap& mainMap, Clock& clock);
void drawEnemies(std::list<Enemy*> enemies,
	std::list<Enemy*>::iterator iterator, RenderWindow& window);
String loadStageImage(int level);
Picture digits("Data/digits.png", 0, 0, 500, 50, 850, 0);
Picture stage(loadStageImage(hero.level),0,0,300,50,50,0);

void loadDigit(int & stageTime, Picture digits, RenderWindow& window, int & stop);