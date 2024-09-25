/*
 * _INx_NF.h
 *
 * Created on: Sep 14, 2024
 * Author: Mwangi Alex. W
 *
 * This header file consists of all the variables and pointers that are to be fed to the CMSIS DSP functions for IIR biquad filter implementation
 * for a notch filter that attenuates 50hZ powerline interference noise. The variables and pointers are declared in the form of a structure
 * upon which every member of the struct is accessed by a pointer. That way, the input arguments of the DSP functions are fed as members of a
 * struct.
 */

#ifndef INC__ADCN_INX_NF_H_
#define INC__ADCN_INX_NF_H_

// MACROS
#define NOOFCOEFFICIENTS 5 // The number of coefficients of one biquad filter stage are 5. Total number of coefficients = number of stages X number of coefficients per stage
#define NOOFS_VARIABLES 2  // The number of variables for each biquad filter are 2. Total number of coefficients = number of stages X number of state variables per stage


//INCLUSIONS
#include "_DMA_Sort.h" // Header file that caters for the sorting of mixed up channel data from the DMA buffer into buffers that contain the data from respective ADC channels
#include "arm_math.h" // Header file necessary for running CMSIS DSP functions

//STRUCTS, VARIABLES AND POINTERS
// The struct that holds all the variables and pointers that are needed to to run the biquad DSP function

typedef struct   // Handles IN1 channel data
{
	uint8_t ADC1_IN1_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC1_IN1_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC1_IN1_pcoeffs; // Pointer to the coefficients array

	float32_t ADC1_IN1_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC1_IN1_pState; //Pointer to the states array

	float32_t *ADC1_IN1_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC1_IN1_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC1_IN1_pdst; // Pointer to the output buffer

	uint32_t ADC1_IN1_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S1; //Instance that is fed to the CMSIS DSP functions

} ADC1_IN1_NF;

extern ADC1_IN1_NF ADC1_IN1_NF_arg; // Variable used initialize the struct in the .c file



typedef struct  // Handles IN2 channel data
{
	uint8_t ADC1_IN2_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC1_IN2_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC1_IN2_pcoeffs; // Pointer to the coefficients array

	float32_t ADC1_IN2_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC1_IN2_pState; //Pointer to the states array

	float32_t *ADC1_IN2_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC1_IN2_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC1_IN2_pdst; // Pointer to the output buffer

	uint32_t ADC1_IN2_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S2; //Instance that is fed to the CMSIS DSP functions

} ADC1_IN2_NF;

extern ADC1_IN2_NF ADC1_IN2_NF_arg;   


typedef struct // Handles IN3 channel data
{
	uint8_t ADC2_IN3_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC2_IN3_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC2_IN3_pcoeffs; // Pointer to the coefficients array

	float32_t ADC2_IN3_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC2_IN3_pState; //Pointer to the states array

	float32_t *ADC2_IN3_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC2_IN3_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC2_IN3_pdst; // Pointer to the output buffer

	uint32_t ADC2_IN3_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S3; //Instance that is fed to the CMSIS DSP functions

} ADC2_IN3_NF;

extern ADC2_IN3_NF ADC2_IN3_NF_arg;



typedef struct // Handles IN4 channel data
{
	uint8_t ADC2_IN4_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC2_IN4_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC2_IN4_pcoeffs; // Pointer to the coefficients array

	float32_t ADC2_IN4_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC2_IN4_pState; //Pointer to the states array

	float32_t *ADC2_IN4_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC2_IN4_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC2_IN4_pdst; // Pointer to the output buffer

	uint32_t ADC2_IN4_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S4; //Instance that is fed to the CMSIS DSP functions

} ADC2_IN4_NF;

extern ADC2_IN4_NF ADC2_IN4_NF_arg;



typedef struct // Handles IN1 channel data
{
	uint8_t ADC3_IN1_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC3_IN1_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC3_IN1_pcoeffs; // Pointer to the coefficients array

	float32_t ADC3_IN1_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC3_IN1_pState; //Pointer to the states array

	float32_t *ADC3_IN1_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC3_IN1_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC3_IN1_pdst; // Pointer to the output buffer

	uint32_t ADC3_IN1_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S5; //Instance that is fed to the CMSIS DSP functions

} ADC3_IN1_NF;

extern ADC3_IN1_NF ADC3_IN1_NF_arg; 


typedef struct // Handles IN2 channel data
{
	uint8_t ADC3_IN2_numstages; // The number of biquad stages for the notch filter. One biquad is of the order 2. Using two stages means our filter is of order 4. Declaration with initialization would result in an error

	float32_t  ADC3_IN2_coeffs[2*NOOFCOEFFICIENTS]; // The coefficients for each biquad stage. The coefficients are declared as an array of size-->Total number of coefficients

	const float32_t *ADC3_IN2_pcoeffs; // Pointer to the coefficients array

	float32_t ADC3_IN2_States[2*NOOFS_VARIABLES]; // A buffer of the size-->Total number of states, is declared and all variables initialized to zero

	float32_t *ADC3_IN2_pState; //Pointer to the states array

	float32_t *ADC3_IN2_psrc; // Pointer to the input or source buffer. The source buffer in this case is one that stores sorted data from channel 1 of ADC1

	float32_t _NF_ADC3_IN2_bfr[ADC_DMA_HALFBUFFERSIZE];

	float32_t *ADC3_IN2_pdst; // Pointer to the output buffer

	uint32_t ADC3_IN2_Blocksize; // Number of samples to be processed. Equal to the source buffer size

	const arm_biquad_cascade_df2T_instance_f32 S6; //Instance that is fed to the CMSIS DSP functions

} ADC3_IN2_NF;

extern ADC3_IN2_NF ADC3_IN2_NF_arg; 

//FUNCTION DECLARATIONS

void init_ADC1_IN1_struct(void);  // Function that initializes the pointer to the source buffer at runtime for channel 1

void init_ADC1_IN1_FO_biquad_filter(void);  // The CMSIS DSP function that initializes the filter coefficients, variables and buffer sizes before filtering commences for channel 1

void update_ADC1_IN1_FO_biquad_filter(void);  // The optimized CMSIS DSP function that handles all the filtering operations and uploads the updated values to the destination buffers for channel 1


void init_ADC1_IN2_struct(void);

void init_ADC1_IN2_FO_biquad_filter(void);

void update_ADC1_IN2_FO_biquad_filter(void);


void init_ADC2_IN3_struct(void);

void init_ADC2_IN3_FO_biquad_filter(void);

void update_ADC2_IN3_FO_biquad_filter(void);


void init_ADC2_IN4_struct(void);

void init_ADC2_IN4_FO_biquad_filter(void);

void update_ADC2_IN4_FO_biquad_filter(void);


void init_ADC3_IN1_struct(void);

void init_ADC3_IN1_FO_biquad_filter(void);

void update_ADC3_IN1_FO_biquad_filter(void);


void init_ADC3_IN2_struct(void);

void init_ADC3_IN2_FO_biquad_filter(void);

void update_ADC3_IN2_FO_biquad_filter(void);


#endif /* INC__ADCN_INX_NF_H_ */
