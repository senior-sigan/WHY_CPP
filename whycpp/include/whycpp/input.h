#ifndef WHYCPP_INPUTS_H
#define WHYCPP_INPUTS_H

#include "buttons.h"

/**
 * @defgroup Input
 * @ingroup WHYCPP_PublicAPI
 * @brief Functions to handle user input
 *
 * @{
 */

/**
 * Check whether the button is being pressed right now or not.
 * @param btn to check
 * @return true if the button is pressed and false otherwise
 */
bool IsPressed(const Button& btn);
/**
 * Check whether the button was being pressed but know is released.
 * So it could be counted as button is clicked.
 * @param btn to check
 * @return true if the button is clicked and false otherwise
 */
bool IsClicked(const Button& btn);

/**
 * Get current mouse (x,y) coordinates and writes them by reference to the arguments.
 * To check whether mouse button is presed or not use IsPressed() and IsClicked() with special Button codes.
 * @param x [out] horizontal coordinate reference
 * @param y [out] vertical coordinate reference
 */
void GetMouse(int& x, int& y);

/** @} */

#endif  // WHYCPP_INPUTS_H
