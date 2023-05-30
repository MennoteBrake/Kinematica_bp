/*
 * Compass.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#include "Compass.hpp"
#include "MathUtils.hpp"
#include "Shape2DUtils.hpp"

Compass::Compass(double stdev) : stdev(stdev){

}

Compass::~Compass() {
}

double Compass::getDirection(const Model::BoundedVector& direction)
{
	double angle = Utils::MathUtils::toDegrees(Utils::Shape2DUtils::getAngle(direction));

	return Utils::MathUtils::deviateData(stdev, angle);
}
