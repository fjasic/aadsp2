#ifndef COMMON_H
#define COMMON_H

#include "stdfix_emu.h"

#define BLOCK_SIZE 16
#define MAX_NUM_CHANNEL 8
#define NUM_CHANNEL_OUT  5

typedef short DSPshort;					/* DSP integer */
typedef unsigned short DSPushort;		/* DSP unsigned integer */
typedef int DSPint;						/* native integer */
typedef fract DSPfract;				    /* DSP fixed-point fractional */
typedef long_accum DSPaccum;            /* DSP Accumulator */

DSPfract  INPUT_GAIN    =  0.5011872336272722;

DSPfract  INPUT_MODE0_LS= 0.15848931924611134;
DSPfract  INPUT_MODE0_C = 1.7782794100389228;

DSPfract  INPUT_MODE1_LS= 0.5011872336272722;
DSPfract  INPUT_MODE1_C = 1.4125375446227544;

DSPfract sampleBuffer[MAX_NUM_CHANNEL][BLOCK_SIZE];

DSPfract tempBuffer[MAX_NUM_CHANNEL][BLOCK_SIZE];

char decibels[50];

char* pEnd;

typedef struct {
	DSPfract  degree;
	DSPfract  gain;
	DSPint whichChannelInvert;
} inverter_data_t;

inverter_data_t data;

enum output_mode_controls {MODE_2_0_0, MODE_3_0_0, MODE_2_2_0,MODE_3_2_0};
output_mode_controls outputMode = MODE_2_0_0;
enum mode_controls {MODE0,MODE1};
mode_controls mode_switch=MODE1;


DSPfract input_gain = DSPfract(0.5011872336272722); // -6dB - default input gain
DSPint enable = 1; // default enable switch

DSPfract dry = 1.0 - data.degree;
DSPfract val;

DSPfract* centralOutput;
DSPfract* lsOutput;
DSPfract* rsOutput;

DSPfract* rightOutput;
DSPfract* leftOutput;

DSPfract* centralInput;
DSPfract* lsInput;
DSPfract* rsInput;

DSPfract* rightInput;
DSPfract* leftInput;



#endif