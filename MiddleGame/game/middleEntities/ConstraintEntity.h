#pragma once
#include "middle_component_table.h"
#include "game_state.h"
#include "MidComp/Constraint.h"
#include "MidComp/MouseSelectable.h"
#include "MidComp/MouseIntersectable.h"

namespace entities{

    inline void initConstraint(middle::GameState* gameState, int index, int indexA, int indexB, float targetDistance){
		middle::MiddleMan shape = middle::createShape(gameState);
		components::Constraint* constraint = middle::addComponent<components::Constraint>(shape);
		middle::addComponent<components::MouseSelectable>(shape);
		middle::addComponent<components::MouseIntersectable>(shape);
		middle::registerShape(gameState, shape);
		constraint->stiffness = middle::DEF_STIFFNESS;
		constraint->targetDistance = targetDistance;
		middle::MiddleMan& shapeA = middle::getShape(gameState, indexA);
		middle::MiddleMan& shapeB = middle::getShape(gameState, indexB);
		constraint->idA = shapeA.id;
		constraint->idB = shapeB.id;
    }
}
