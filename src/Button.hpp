#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Config.hpp"

#include "Widgets.hpp"

#include <functional>
#include <string>

namespace Application
{
	/**
	 * Utility function that creates a Button with aLabel that binds the given ActionFunction with the
	 * wxEVT_COMMAND_BUTTON_CLICKED of the button.
	 *
	 * @param aParent
	 * @param aLabel
	 * @param anActionFunction
	 * @return
	 */
	template< typename ActionFunction>
	wxButton* makeButton( wxWindow* aParent,
						const std::string& aLabel,
						const ActionFunction anActionFunction)
	{
		wxButton* button = new wxButton( aParent, wxID_ANY, aLabel);
		button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, anActionFunction);
		return button;
	}
} // namespace Application

#endif // DANU_BUTTON_HPP_
