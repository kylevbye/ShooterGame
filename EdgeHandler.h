#pragma once
#include "Entity.h"

extern float screenWidth, screenHeight;

class EdgeHandler {

public:
	
	//	Edge Constants 
	enum EdgeStrategies { LOCK, WRAP, PAN };
	enum EdgeDirection { X_AXIS, Y_AXIS };

private:

	float minX, maxX;
	float minY, maxY;
	float border;
	Entity *controlledEntity;
	EdgeStrategies verticalStrategy;
	EdgeStrategies horizontalStrategy;

public:
	
	//	Getters

	float getMinX();
	float getMaxX();
	float getMinY();
	float getMaxY();
	Entity *getControlledEntity();
	EdgeStrategies getVerticalStrategy();
	EdgeStrategies getHorizontalStrategy();

	//	Setters

	void setMinX(float minX);
	void setMaxX(float maxX);
	void setMinY(float minY);
	void setMaxY(float maxY);
	void setControlledEntity(Entity *controlledEntity);
	void setVerticalStrategy(EdgeStrategies verticalStrategy);
	void setHorizontalStrategy(EdgeStrategies horizontalStrategy);

	//	Functions

	void handleEdges();

	//	Constructors

	EdgeHandler();
	EdgeHandler(Entity *controlledEntity, float minX, float maxX, float minY, float maxY);
	EdgeHandler(Entity *controlledEntity, float minX, float maxX, float minY, float maxY, EdgeStrategies horizontalStrategy, EdgeStrategies verticalStrategy);

	//	Helpers

	void lock(EdgeDirection axis);
	void wrap(EdgeDirection axis);
	void pan(EdgeDirection axis);





};

