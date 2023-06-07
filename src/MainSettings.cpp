#include "MainSettings.hpp"

namespace Application
{
	/**
	 *
	 */
	MainSettings::MainSettings() : drawOpenSet(true), speed(10), worldNumber(0)
	{
	}
	/**
	 *
	 */
	MainSettings::~MainSettings()
	{
	}
	/**
	 *
	 */
	bool MainSettings::getDrawOpenSet() const
	{
		return drawOpenSet;
	}
	/**
	 *
	 */
	void MainSettings::setDrawOpenSet( bool aDrawOpenSet)
	{
		drawOpenSet = aDrawOpenSet;
	}
	/**
	 *
	 */
	unsigned long MainSettings::getSpeed() const
	{
		return speed;
	}
	/**
	 *
	 */
	void MainSettings::setSpeed( unsigned long aSpeed)
	{
		speed = aSpeed;
	}
	/**
	 *
	 */
	unsigned long MainSettings::getWorldNumber() const
	{
		return worldNumber;
	}
	/**
	 *
	 */
	void MainSettings::setWorldNumber( unsigned long aWorldNumber)
	{
		worldNumber = aWorldNumber;
	}

	unsigned long MainSettings::getFilterSelected() const
	{
		return filterSelected;
	}

	void MainSettings::setFilterSelected( unsigned long aFilterSelected)
	{
		filterSelected = aFilterSelected;
	}
} /* namespace Application */
