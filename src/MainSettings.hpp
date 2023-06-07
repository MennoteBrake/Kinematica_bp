#ifndef MAINSETTINGS_HPP_
#define MAINSETTINGS_HPP_

#include "Config.hpp"

namespace Application
{

	/*
	 *
	 */
	class MainSettings
	{
		public:
			/**
			 *
			 */
			MainSettings();
			/**
			 *
			 */
			virtual ~MainSettings();
			/**
			 *
			 */
			bool getDrawOpenSet() const;
			/**
			 *
			 */
			void setDrawOpenSet( bool aDrawOpenSet);
			/**
			 *
			 */
			unsigned long getSpeed() const;
			/**
			 *
			 */
			void setSpeed( unsigned long aSpeed);
			/**
			 *
			 */
			unsigned long getWorldNumber() const;
			/**
			 *
			 */
			void setWorldNumber( unsigned long aWorldNumber);
			/**
			 * Gets the number that is used for selecting a filter
			 */
			unsigned long getFilterSelected() const;
			/**
			 * Sets the number that is used for selecting the filter
			 */
			void setFilterSelected( unsigned long aFilterSelected);

		private:
			bool drawOpenSet;
			unsigned long speed;
			unsigned long worldNumber;
			unsigned long filterSelected;
	};

} /* namespace Application */

#endif /* SRC_MAINSETTINGS_HPP_ */
