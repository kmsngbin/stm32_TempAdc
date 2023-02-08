/*
 * filter.c
 *
 *  Created on: 2023. 2. 6.
 *      Author: npedu024
 */

#include "filter.h"

uint16_t AvgFilter(uint16_t inData)
{
	static uint16_t filterBuffer[100]; //100개의 filterBuffer 생성.
	static uint16_t sumValue = 0;
	static uint8_t bufPos = 0; // Buffer Position.

	// 합계에서 현재 위치의 buffer 값을 빼기.
	sumValue -= filterBuffer[bufPos];

	// 현재 위치의 buffer 값 갱신
	filterBuffer[bufPos] = inData;

	// 합계에 현재 위치의 buffer 값을 더하기.
	sumValue += filterBuffer[bufPos];

	bufPos++;
	bufPos %= 100;

	return sumValue / 100;
}

double Kalman(double measurement)
{
	// Kalman filter setup
	static double P = 1.0;
	static double varP = 0.0001;  // pow(0.01, 2)
	static double R = 0.25;  //pow(0.5, 2);
	static double K = 1.0;
	static double X = 20.0;

	// Kalman Simple Filter
	P = P + varP;
	K = P / (P + R);
	X = (K * measurement) + (1 - K) * X;
	P = (1 - K) * P;

	return X;
}
