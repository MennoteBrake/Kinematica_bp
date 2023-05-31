/*
 * Lidar.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#include "Lidar.hpp"
#include "MathUtils.hpp"
#include "RobotWorld.hpp"
#include "Wall.hpp"
#include "Shape2DUtils.hpp"

Lidar::Lidar() : stdev(0)
{

}

Lidar::Lidar(double stdev) : stdev(stdev)
{

}


Lidar::~Lidar()
{

}


std::vector<double> Lidar::measureDistance(const wxPoint& robotPosition)
{
	std::vector<double> distances;
	std::vector< Model::WallPtr > walls = Model::RobotWorld::getRobotWorld().getWalls();
	const uint8_t degreesToAddPerBeam = (360 / amountOfLidarBeams);
	uint16_t degrees = 0;

	const short int laserBeamLength = 1024;

	double dist;
	for(uint8_t i = 0; i < amountOfLidarBeams; ++i)
	{
		dist = 0;
		for(std::shared_ptr< Model::Wall > wall : walls)
		{
			wxPoint wallPoint1 = wall->getPoint1();
			wxPoint wallPoint2 = wall->getPoint2();

			wxPoint laserEndpoint{static_cast<int>(robotPosition.x + std::cos(degrees) * Utils::MathUtils::deviateData(stdev, laserBeamLength)),
									static_cast<int>(robotPosition.y + std::sin(degrees) * Utils::MathUtils::deviateData(stdev, laserBeamLength))};

			// without the stdev at the geting walls
//			wxPoint laserEndpoint{static_cast<int>(robotPosition.x + std::cos(degrees) * laserBeamLength),
//									static_cast<int>(robotPosition.y + std::sin(degrees) * laserBeamLength)};

			wxPoint interSection = Utils::Shape2DUtils::getIntersection( wallPoint1, wallPoint2, robotPosition, laserEndpoint);

			if(interSection != wxDefaultPosition)
			{
				dist = Utils::Shape2DUtils::distance(robotPosition,interSection);
			}
		}
		if (dist < 1025)
		{
			distances.push_back(Utils::MathUtils::deviateData(stdev, dist));
		}
		else
		{
			distances.push_back(0); //add an empty measurement
		}
		degrees += degreesToAddPerBeam;
	}

	return distances;
}
