/*
 * ParticleFilter.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#ifndef SRC_PARTICLEFILTER_HPP_
#define SRC_PARTICLEFILTER_HPP_
#include "Point.hpp"
#include <vector>
#include "FileReader.hpp"
#include <random>

struct Particle {
	int x;
	int y;
	double probability;
};

class ParticleFilter {
public:
	/**
	 * Constructs a ParticleFilter object
	 */
	ParticleFilter();
	virtual ~ParticleFilter();
	/**
	 * Calculates the belief, and runs the particle filter
	 */
	void calculatePosition(const wxPoint& position, const std::vector<double>& robotMeasurement);
	/**
	 * Generates the initial particles
	 */
	void generateParicles(const uint16_t& numberOfParticles);
	/**
	 * Getter for the particle vector
	 */
	std::vector<Particle> getParticles() const;
	/**
	* Setter for the particle vector
	*/
	void setParticles(std::vector<Particle> particles);
	/**
	 * Getter for the driven route
	 */
	std::vector<wxPoint> getDrivenRoute() const;
	/**
	 * Clears the driven route vector
	 */
	void clearDrivenRoute();
	/**
	 * Getter for the belief
	 */
	wxPoint getBelief() const;
	/**
	 * Setter for the belief
	 */
	void setBelief(wxPoint belief);

private:
	/**
	 * The function for the predict state
	 */
	void predictState(const wxPoint& position);
	/**
	 * Function to adjust the state
	 */
	void adjustState(const std::vector<double>& robotMeasurement);
	/**
	 * Function to resample
	 */
	void ResampleState();

	std::mt19937 rng;
	uint16_t worldSize = 1024;
	std::vector<Particle> particles;
	std::vector<wxPoint> drivenRoute;
	wxPoint belief;
	FileReader fileReader;
	const std::string settingFileName = "sensor_configurations.txt";

};

#endif /* SRC_PARTICLEFILTER_HPP_ */
