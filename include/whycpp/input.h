#ifndef WHYCPP_INPUTS_H
#define WHYCPP_INPUTS_H

#include <whycpp/buttons.h>

class Context;

/**
 * @defgroup Input
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to handle user input
 *
 * @{
 */

/**
 * Check whether the button is being pressed right now or not.
 * @param context of the application
 * @param btn to check
 * @return true if the button is pressed and false otherwise
 */
bool IsPressed(const Context &context, const Button& btn);
/**
 * Check whether the button was being pressed but know is released.
 * So it could be counted as button is clicked.
 * @param context
 * @param btn
 * @return
 */
bool IsClicked(const Context &context, const Button& btn);

/** @} */

#endif //WHYCPP_INPUTS_H
