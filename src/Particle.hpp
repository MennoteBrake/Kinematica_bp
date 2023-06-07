/*
 * Particle.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */
#include "Point.hpp"

#ifndef SRC_PARTICLE_HPP_
#define SRC_PARTICLE_HPP_

class Particle {
public:
	Particle();
	Particle(const wxPoint& pos);
	virtual ~Particle();

	wxPoint getPosition();

	void setPosition(const wxPoint& pos);

	double getProbability() const;

	void setProbability(double probability);

private:
	wxPoint position;
	double probability;

};

#endif /* SRC_PARTICLE_HPP_ */
