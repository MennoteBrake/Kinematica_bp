/*
 * ParticleFilter.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 *
 *
 *  In this object the formula's from ILectureOnline have been used instead of the one's from Thrun.
 *  This was done because these formulas were able to be written as a command with the functions.
 *  In the WoR-Robots-Dictaat.pdf there is a table that translates this to the functions from Thrun. See Tabel 10.1
 */

#include "ParticleFilter.hpp"
#include "Lidar.hpp"

ParticleFilter::ParticleFilter()
{
	fileReader.setFileName(FileReader::settingFileName);
	std::random_device rd;
	rng = std::mt19937(rd());
}

ParticleFilter::~ParticleFilter()
{
}

void ParticleFilter::calculatePosition(const wxPoint& position, const std::vector<double>& robotMeasurement)
{
	predictState(position);
	adjustState(robotMeasurement);
	ResampleState();

	Particle bestParticle;
	for(Particle &particle : particles)
	{
		//If it has a better weight/probability, then replace the particle
		if(bestParticle.probability < particle.probability)
		{
			bestParticle = particle;
		}
	}
	belief = wxPoint(bestParticle.x, bestParticle.y);

	drivenRoute.push_back(belief);
}

void ParticleFilter::generateParicles(const uint16_t& numberOfParticles)
{
	std::uniform_int_distribution<> xDistribution(0, worldSize);
	std::uniform_int_distribution<> yDistribution(0, worldSize);

	for(uint16_t i = 0; i < numberOfParticles; ++i)
	{
		Particle particle;
		particle.x = xDistribution(rng);
		particle.y = yDistribution(rng);
		particle.probability = 0;

		particles.push_back(particle);
	}
}

void ParticleFilter::predictState(const wxPoint& position)
{
	std::uniform_int_distribution<> random(0, 2);

	for (Particle &particle : particles)
	{
		particle.x = particle.x + (position.x - belief.x + random(rng));
		particle.y = particle.y + (position.y - belief.y + random(rng));
	}
}
void ParticleFilter::adjustState(const std::vector<double>& robotMeasurement)
{
	double stdev = fileReader.readSettingFromFile(FileReader::Setting::LIDAR_STDEV);
	Lidar lidar(stdev);

	for (Particle &particle : particles)
	{
		std::vector<double> measurement = lidar.measureDistance(wxPoint(particle.x, particle.y));

		double difference = 0;

		for (uint16_t i = 0; i < (uint16_t)measurement.size(); ++i)
		{
			difference += std::sqrt(std::pow(robotMeasurement.at(i) - measurement.at(i), 2));
		}

		particle.probability = (difference != 0) ? (1/difference) : 1;
	}
}

void ParticleFilter::ResampleState()
{
	std::vector<double> weights;
	for (Particle &particle : particles)
	{
		weights.push_back(particle.probability);
	}

	std::vector<Particle> resampled;
	std::discrete_distribution<> discreteDist(weights.begin(), weights.end());
	for (uint16_t i = 0; i < (uint16_t)particles.size(); ++i)
	{
		resampled.push_back(particles[discreteDist(rng)]);
	}

	particles = resampled;
}

void ParticleFilter::clearDrivenRoute()
{
	drivenRoute.clear();
}

std::vector<Particle> ParticleFilter::getParticles() const
{
	return particles;
}

void ParticleFilter::setParticles(std::vector<Particle> particles)
{
	this->particles = particles;
}
std::vector<wxPoint> ParticleFilter::getDrivenRoute() const
{
	return drivenRoute;
}

wxPoint ParticleFilter::getBelief() const {
	return belief;
}

void ParticleFilter::setBelief(wxPoint belief) {
	this->belief = belief;
}
