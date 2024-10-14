/*
 * _INx_NF.c
 *
 *  Created on: Sep 14, 2024
 *  Author: Mwangi Alex. W
 * 
 *  Defines all the functions that filter the sorted data by eliminating 50Hz power line interference
 */

//INCLUSIONS
#include <_ADCn_INx_NF.h>

// GLOBAL BUFFER DECLARATIONS
float32_t ADC1_IN1_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC1_IN1_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC1_IN1_NF ADC1_IN1_NF_arg = // Initializes the struct declared in the header file
	{
	    .ADC1_IN1_numstages = 2,  // Number of stages in the biquad filter

	    .ADC1_IN1_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC1_IN1_pcoeffs = ADC1_IN1_coeffs,  // Pointing to the global coefficient array

	    .ADC1_IN1_States = {0.0f},  // Zero-initialize the state variables

	    .ADC1_IN1_pState = ADC1_IN1_States,  // Pointing to the global state array

	    .ADC1_IN1_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC1_IN1_pdst = ADC1_IN1_NF_arg._NF_ADC1_IN1_bfr,  // Initialize destination buffer pointer

	    .ADC1_IN1_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S1 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};



float32_t ADC1_IN2_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC1_IN2_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC1_IN2_NF ADC1_IN2_NF_arg =
	{
	    .ADC1_IN2_numstages = 2,  // Number of stages in the biquad filter

	    .ADC1_IN2_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC1_IN2_pcoeffs = ADC1_IN2_coeffs,  // Pointing to the global coefficient array

	    .ADC1_IN2_States = {0.0f},  // Zero-initialize the state variables

	    .ADC1_IN2_pState = ADC1_IN2_States,  // Pointing to the global state array

	    .ADC1_IN2_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC1_IN2_pdst = ADC1_IN2_NF_arg._NF_ADC1_IN2_bfr,  // Initialize destination buffer pointer

	    .ADC1_IN2_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S2 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};


// ASSUMING THE ADC1_DMA_sort_ptr IS ALREADY INITIALIZED ELSEWHERE IN YOUR CODE
extern ADC1_DMA_sort*ADC1_DMA_sort_ptr;



// INITIALIZING THE STRUCT INSTANCE
void init_ADC1_IN1_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC1_IN1_NF_arg.ADC1_IN1_psrc = (float32_t *)(ADC1_DMA_sort_ptr->ADC1_IN1_bfr);   // Typecasting. Converts the data in IN1 data buffer to floating point values. Assigns the source buffer at runtime
  }

void init_ADC1_IN1_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC1_IN1_NF_arg.S1,  // Pointer to the instance
	        ADC1_IN1_NF_arg.ADC1_IN1_numstages,                                     // Number of stages (2 in this case)
	        ADC1_IN1_NF_arg.ADC1_IN1_pcoeffs,                                       // Pointer to coefficients array
	        ADC1_IN1_NF_arg.ADC1_IN1_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC1_IN1_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC1_IN1_NF_arg.S1, ADC1_IN1_NF_arg.ADC1_IN1_psrc , ADC1_IN1_NF_arg.ADC1_IN1_pdst, ADC1_IN1_NF_arg.ADC1_IN1_Blocksize);
   }



void init_ADC1_IN2_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC1_IN2_NF_arg.ADC1_IN2_psrc = (float32_t *)(ADC1_DMA_sort_ptr->ADC1_IN2_bfr);  // Typecasting. Assigned at runtime
  }

void init_ADC1_IN2_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC1_IN2_NF_arg.S2,  // Pointer to the instance
	        ADC1_IN2_NF_arg.ADC1_IN2_numstages,                                     // Number of stages (2 in this case)
	        ADC1_IN2_NF_arg.ADC1_IN2_pcoeffs,                                       // Pointer to coefficients array
	        ADC1_IN2_NF_arg.ADC1_IN2_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC1_IN2_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC1_IN2_NF_arg.S2, ADC1_IN2_NF_arg.ADC1_IN2_psrc , ADC1_IN2_NF_arg.ADC1_IN2_pdst, ADC1_IN2_NF_arg.ADC1_IN2_Blocksize);
   }
