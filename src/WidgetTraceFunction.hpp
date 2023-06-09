#ifndef WIDGETTRACEFUNCTION_HPP_
#define WIDGETTRACEFUNCTION_HPP_

#include "Config.hpp"

#include "ITraceFunction.hpp"

namespace Application
{
	class LogTextCtrl;

	/**
	 *
	 */
	class WidgetTraceFunction : public Base::ITraceFunction
	{
		public:
			/**
			 * @param aLogTextCtrl The TextCtrl derived class that will receive the trace string as message
			 */
			explicit WidgetTraceFunction( Application::LogTextCtrl* aLogTextCtrl);
			/**
			 *
			 * @param aText The text that will be send to the final trace destination.
			 */
			virtual void trace( const std::string& aText) override;
		private:
			/**
			 *
			 */
			Application::LogTextCtrl* outputControl;
	};
} // namespace Application
#endif // WIDGETTRACEFUNCTION_HPP_
