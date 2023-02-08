/*
 * filter.h
 *
 *  Created on: 2023. 2. 6.
 *      Author: npedu024
 */

#ifndef INC_FILTER_H_
#define INC_FILTER_H_

#include "main.h"

uint16_t AvgFilter(uint16_t inData);
double Kalman(double measurement);

#endif /* INC_FILTER_H_ */
