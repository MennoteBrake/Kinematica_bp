/*
 * Particle.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#include "Particle.hpp"

Particle::Particle() : position(wxPoint(0,0)), probability(0)
{

}

Particle::Particle(const wxPoint& pos) : position(pos), probability(0)
{

}

Particle::~Particle()
{
}

wxPoint Particle::getPosition()
{
	return position;
}

void Particle::setPosition(const wxPoint& pos)
{
	position = pos;
}

double Particle::getProbability() const
{
	return probability;
}

void Particle::setProbability(double probability)
{
	this->probability = probability;
}

