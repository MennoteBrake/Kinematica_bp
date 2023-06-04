/*
 * Odometry.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#include "Odometry.hpp"
#include "MathUtils.hpp"

Odometry::Odometry() : stdev(0)
{
	// TODO Auto-generated constructor stub

}

Odometry::Odometry(double stdev) : stdev(stdev)
{

}

Odometry::~Odometry() {
	// TODO Auto-generated destructor stub
}

double Odometry::measureOdometry(double speed)
{
	return Utils::MathUtils::deviateData(stdev, speed);
}


