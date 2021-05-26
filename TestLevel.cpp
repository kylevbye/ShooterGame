#include "TestLevel.h"

void Game::TestLevel::update(float dt, const ControlState &controlState) {

	float dx = 0;
	float dy = 0;
	float mvmtSpeed = 150.f;
	float accelVal = 3.f;

	bui.reset();

	//if (keyStates.W_DOWN) dy -= mvmtSpeed;
	if (controlState.movedLeft()) {
		//dx -= mvmtSpeed;
		option = (option==BattleUI::Options::FIGHT) ? BattleUI::Options::SPARE : (BattleUI::Options) ((int) option-1);
	}
	//if (keyStates.S_DOWN) dy += mvmtSpeed;
	if (controlState.movedRight()) {
		//dx += mvmtSpeed;
		option = (option==BattleUI::Options::SPARE) ? BattleUI::Options::FIGHT : (BattleUI::Options) ((int) option+1);
	}

	bui.select(option);

	dx = 0;
	dy = 0;
	if (controlState.movingUp()) dy -= mvmtSpeed;
	if (controlState.movingLeft()) dx -= mvmtSpeed;
	if (controlState.movingDown()) dy += mvmtSpeed;
	if (controlState.movingRight()) dx += mvmtSpeed;
	entity2.setVelocity(dx, dy);

	locker.handleEdges();

	//SDL_Log("E:{x:%f, y:%f, w:%f, h:%f} Rect: {x:%f, y:%f, w:%f, h:%f}", entity2.getPosition().x, entity2.getPosition().y, entity2.getWidth(), entity2.getHeight(), entity2.getCollisionRect().position.x, entity2.getCollisionRect().position.y, entity2.getCollisionRect().width, entity2.getCollisionRect().height);

	bui.update(dt);

	Level::update(dt, controlState);


}

void Game::TestLevel::updateEvents(Uint32 time, float dt) {

	entity1.setColor({255, 255, 255});
	entity2.setColor({255, 255, 255});

	if (entity1.intersectsWith(entity2)) {
		entity1.setColor({255, 0, 0});
		entity2.setColor({255, 0, 0});
	}

	/*
	float du = 1;
	if (goUp) {
		upAndDownThing += du*dt;
		if (upAndDownThing>5.f) {
			upAndDownThing = 5.f;
			goUp = false;
		}
	}
	else {
		upAndDownThing -= du*dt;
		if (upAndDownThing<.5f) {
			upAndDownThing = .5f;
			goUp = true;
		}
	}

	rectangle.setScaleX(upAndDownThing);
	rectangle.setScaleY(upAndDownThing);*/

}

void Game::TestLevel::setup() {

	Level::setup();
	done = false;
	nextLevelCode = Levels::MAIN_MENU;

}

void Game::TestLevel::render(SDL_Renderer *renderer) {

	Level::render(renderer);

	entity1.getCollisionRect().render();
	entity2.getCollisionRect().render();
	bui.render();

}

Game::TestLevel::TestLevel() : entity1("res/img/asgoreLookDown.png"), entity2("res/img/soul2.png"), rectangle("res/img/rectangle.png"), upAndDownThing(0), goUp(true), bui(screenWidth*.6f, screenHeight*.07, {(screenWidth-screenWidth*.6f)/2.f, screenHeight-screenHeight/8}), option(BattleUI::Options::FIGHT), locker() {

	std::vector<Entity *> screenObjects;

	//	Entity 1
	Collision::Rectangle eR1;
	eR1.width = entity1.getWidth();
	eR1.height = entity1.getHeight();
	entity1.setCollisionShape(eR1);
	screenObjects.push_back(&entity1);

	//	Entity 2
	Collision::Rectangle eR2;
	float scaleW2 = 1.f;
	float scaleH2 = .8f;
	eR2.width = (entity2.getWidth())*scaleW2;
	eR2.height = entity2.getHeight()*scaleH2;
	entity2.setCollisionShape(eR2);
	entity2.setPosition(screenWidth/2-entity2.getWidth()*scaleH2/2, screenHeight/2-entity2.getHeight()/2);
	screenObjects.push_back(&entity2);


	rectangle.setScale(4);
	//rectangle.setColor({255,0,0});
	rectangle.setPosition(screenWidth/2, screenHeight/2);
	rectangle.setCentered(true);
	screenObjects.push_back(&rectangle);

	//	locker
	locker.setControlledEntity(&entity2);
	locker.setMinX(rectangle.getX()-rectangle.getWidth()*rectangle.getScaleX()/2+entity2.getWidth()/2);
	locker.setMaxX(locker.getMinX()+rectangle.getWidth()*rectangle.getScaleX()-entity2.getWidth());
	locker.setMinY(rectangle.getY()-rectangle.getHeight()*rectangle.getScaleY()/2+entity2.getHeight()/2);
	locker.setMaxY(locker.getMinY()+rectangle.getHeight()*rectangle.getScaleY()-entity2.getHeight());
	locker.setHorizontalStrategy(EdgeHandler::EdgeStrategies::LOCK);
	locker.setVerticalStrategy(EdgeHandler::EdgeStrategies::LOCK);

	nextLevelCode = Levels::MAIN_MENU;

	Game::Stage *mainStage = loadStage(screenObjects);
	addStage(mainStage);

}

Game::TestLevel::~TestLevel() {
}
