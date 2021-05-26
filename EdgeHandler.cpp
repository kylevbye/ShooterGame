#include "EdgeHandler.h"

float EdgeHandler::getMinX() {
    return minX;
}

float EdgeHandler::getMaxX() {
    return maxX;
}

float EdgeHandler::getMinY() {
    return minY;
}

float EdgeHandler::getMaxY() {
    return maxY;
}

Entity *EdgeHandler::getControlledEntity() {
    return controlledEntity;
}

EdgeHandler::EdgeStrategies EdgeHandler::getVerticalStrategy() {
    return verticalStrategy;
}

EdgeHandler::EdgeStrategies EdgeHandler::getHorizontalStrategy() {
    return horizontalStrategy;
}

void EdgeHandler::setMinX(float minX) {
    this->minX = minX;
}

void EdgeHandler::setMaxX(float maxX) {
    this->maxX = maxX;
}

void EdgeHandler::setMinY(float minY) {
    this->minY = minY;
}

void EdgeHandler::setMaxY(float maxY) {
    this->maxY = maxY;
}

void EdgeHandler::setControlledEntity(Entity *controlledEntity) {
    this->controlledEntity = controlledEntity;
}

void EdgeHandler::setVerticalStrategy(EdgeStrategies verticalStrategy) {
    this->verticalStrategy = verticalStrategy;
}

void EdgeHandler::setHorizontalStrategy(EdgeStrategies horizontalStrategy) {
    this->horizontalStrategy = horizontalStrategy;
}

void EdgeHandler::handleEdges() {

    switch (horizontalStrategy) {

        case LOCK:
            lock(X_AXIS);
            break;

        case WRAP:
            wrap(X_AXIS);
            break;

        case PAN:
            pan(X_AXIS);
            break;

    }

    switch (verticalStrategy) {

        case LOCK:
            lock(Y_AXIS);
            break;

        case WRAP:
            wrap(Y_AXIS);
            break;

        case PAN:
            pan(Y_AXIS);
            break;

    }

}

EdgeHandler::EdgeHandler() 
    : minX(0), maxX(0), minY(0), maxY(0), border(0), controlledEntity(nullptr), verticalStrategy(LOCK), horizontalStrategy(LOCK) {}

EdgeHandler::EdgeHandler(Entity *controlledEntity, float minX, float maxX, float minY, float maxY)
    : minX(minX), maxX(maxX), minY(minY), maxY(maxY), border(0), controlledEntity(controlledEntity), verticalStrategy(LOCK), horizontalStrategy(LOCK) {

}

EdgeHandler::EdgeHandler(Entity *controlledEntity, float minX, float maxX, float minY, float maxY, EdgeStrategies horizontalStrategy, EdgeStrategies verticalStrategy) 
    : minX(minX), maxX(maxX), minY(minY), maxY(maxY), border(0), controlledEntity(controlledEntity), verticalStrategy(verticalStrategy), horizontalStrategy(horizontalStrategy) { }

void EdgeHandler::lock(EdgeDirection axis) {

    float x = controlledEntity->getX();
    float y = controlledEntity->getY();
    float width = controlledEntity->getWidth();
    float height = controlledEntity->getHeight();

    switch (axis) {

        case X_AXIS:
            if (x>maxX-width) controlledEntity->setX(maxX-width);
            else if (x<minX) controlledEntity->setX(minX);
            break;

        case Y_AXIS:
            if (y>maxY-height) controlledEntity->setY(maxY-height);
            else if (y<minY) controlledEntity->setY(minY);
            break;

    }

}

void EdgeHandler::wrap(EdgeDirection axis) {

    float x = controlledEntity->getX();
    float y = controlledEntity->getY();
    float width = controlledEntity->getWidth();
    float height = controlledEntity->getHeight();

    switch (axis) {

        case X_AXIS:
            if (x>maxX) controlledEntity->setX(minX-width);
            else if (x<minX-width) controlledEntity->setX(maxX);
            break;

        case Y_AXIS:
            if (y>maxY) controlledEntity->setY(minY-height);
            else if (y<minY-height) controlledEntity->setY(maxY);
            break;

    }

}

void EdgeHandler::pan(EdgeDirection axis) {
    SDL_Log("Calling Unimplemented Method: EdgeHandler::pan(EdgeDirection)");
}
