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


float32_t ADC2_IN3_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC2_IN3_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC2_IN3_NF ADC2_IN3_NF_arg =
	{
	    .ADC2_IN3_numstages = 2,  // Number of stages in the biquad filter

	    .ADC2_IN3_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC2_IN3_pcoeffs = ADC2_IN3_coeffs,  // Pointing to the global coefficient array

	    .ADC2_IN3_States = {0.0f},  // Zero-initialize the state variables

	    .ADC2_IN3_pState = ADC2_IN3_States,  // Pointing to the global state array

	    .ADC2_IN3_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC2_IN3_pdst = ADC2_IN3_NF_arg._NF_ADC2_IN3_bfr,  // Initialize destination buffer pointer

	    .ADC2_IN3_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S3 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};

float32_t ADC2_IN4_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC2_IN4_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC2_IN4_NF ADC2_IN4_NF_arg =
	{
	    .ADC2_IN4_numstages = 2,  // Number of stages in the biquad filter

	    .ADC2_IN4_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC2_IN4_pcoeffs = ADC2_IN4_coeffs,  // Pointing to the global coefficient array

	    .ADC2_IN4_States = {0.0f},  // Zero-initialize the state variables

	    .ADC2_IN4_pState = ADC2_IN4_States,  // Pointing to the global state array

	    .ADC2_IN4_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC2_IN4_pdst = ADC2_IN4_NF_arg._NF_ADC2_IN4_bfr,  // Initialize destination buffer pointer

	    .ADC2_IN4_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S4 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};

// ASSUMING THE ADC1_DMA_sort_ptr IS ALREADY INITIALIZED ELSEWHERE IN YOUR CODE
extern ADC2_DMA_sort*ADC2_DMA_sort_ptr;



float32_t ADC3_IN1_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC3_IN1_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC3_IN1_NF ADC3_IN1_NF_arg =
	{
	    .ADC3_IN1_numstages = 2,  // Number of stages in the biquad filter

	    .ADC3_IN1_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC3_IN1_pcoeffs = ADC3_IN1_coeffs,  // Pointing to the global coefficient array

	    .ADC3_IN1_States = {0.0f},  // Zero-initialize the state variables

	    .ADC3_IN1_pState = ADC3_IN1_States,  // Pointing to the global state array

	    .ADC3_IN1_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC3_IN1_pdst = ADC3_IN1_NF_arg._NF_ADC3_IN1_bfr,  // Initialize destination buffer pointer

	    .ADC3_IN1_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S5 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};


float32_t ADC3_IN2_coeffs[2 * NOOFCOEFFICIENTS] =
{
    // First Biquad Stage coefficients
		 /*b0-b2*/ 0.9660f,  -3.9793f,  5.9654f, /*a1-a2*/ 3.9860f,  -5.9653f,

    // Second Biquad Stage coefficients
		 /*b0-b2*/ 1.0000f,  -3.9793f,  0.9966f, /*a1-a2*/ -3.9725f,  -0.9932f
};

float32_t ADC3_IN2_States[2 * NOOFS_VARIABLES] = {0.0f};  // Initialize state variables to 0

ADC3_IN2_NF ADC3_IN2_NF_arg =
	{
	    .ADC3_IN2_numstages = 2,  // Number of stages in the biquad filter

	    .ADC3_IN2_coeffs=  // This will copy the coefficients to the local array within the struct
	    {
	        0.9660f,  -3.9793f,  5.9654f,  3.9860f,  -5.9653f,
	        1.0000f,  -3.9793f,  0.9966f,  -3.9725f,  -0.9932f
	    },

	    .ADC3_IN2_pcoeffs = ADC3_IN2_coeffs,  // Pointing to the global coefficient array

	    .ADC3_IN2_States = {0.0f},  // Zero-initialize the state variables

	    .ADC3_IN2_pState = ADC3_IN2_States,  // Pointing to the global state array

	    .ADC3_IN2_psrc = NULL,  // Initialize to NULL, assign at runtime

	    .ADC3_IN2_pdst = ADC3_IN2_NF_arg._NF_ADC3_IN2_bfr,  // Initialize destination buffer pointer

	    .ADC3_IN2_Blocksize = ADC_DMA_HALFBUFFERSIZE,

	    .S6 = {0},  // Initialize the CMSIS DSP biquad filter instance (you will need to initialize it properly at runtime)
	};


// ASSUMING THE ADC1_DMA_sort_ptr IS ALREADY INITIALIZED ELSEWHERE IN YOUR CODE
extern ADC3_DMA_sort*ADC3_DMA_sort_ptr;


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



void init_ADC2_IN3_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC2_IN3_NF_arg.ADC2_IN3_psrc = (float32_t *)(ADC2_DMA_sort_ptr->ADC2_IN3_bfr);  // Typecasting. Assigned at runtime
  }

void init_ADC2_IN3_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC2_IN3_NF_arg.S3,  // Pointer to the instance
	        ADC2_IN3_NF_arg.ADC2_IN3_numstages,                                     // Number of stages (2 in this case)
	        ADC2_IN3_NF_arg.ADC2_IN3_pcoeffs,                                       // Pointer to coefficients array
	        ADC2_IN3_NF_arg.ADC2_IN3_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC2_IN3_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC2_IN3_NF_arg.S3, ADC2_IN3_NF_arg.ADC2_IN3_psrc , ADC2_IN3_NF_arg.ADC2_IN3_pdst, ADC2_IN3_NF_arg.ADC2_IN3_Blocksize);
   }




void init_ADC2_IN4_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC2_IN4_NF_arg.ADC2_IN4_psrc = (float32_t *)(ADC2_DMA_sort_ptr->ADC2_IN4_bfr);  // Typecasting. Assigned at runtime
  }

void init_ADC2_IN4_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC2_IN4_NF_arg.S4,  // Pointer to the instance
	        ADC2_IN4_NF_arg.ADC2_IN4_numstages,                                     // Number of stages (2 in this case)
	        ADC2_IN4_NF_arg.ADC2_IN4_pcoeffs,                                       // Pointer to coefficients array
	        ADC2_IN4_NF_arg.ADC2_IN4_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC2_IN4_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC2_IN4_NF_arg.S4, ADC2_IN4_NF_arg.ADC2_IN4_psrc , ADC2_IN4_NF_arg.ADC2_IN4_pdst, ADC2_IN4_NF_arg.ADC2_IN4_Blocksize);
   }




void init_ADC3_IN1_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC3_IN1_NF_arg.ADC3_IN1_psrc = (float32_t *)(ADC3_DMA_sort_ptr->ADC3_IN1_bfr);  // Typecasting. Assigned at runtime
  }

void init_ADC3_IN1_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC3_IN1_NF_arg.S5,  // Pointer to the instance
	        ADC3_IN1_NF_arg.ADC3_IN1_numstages,                                     // Number of stages (2 in this case)
	        ADC3_IN1_NF_arg.ADC3_IN1_pcoeffs,                                       // Pointer to coefficients array
	        ADC3_IN1_NF_arg.ADC3_IN1_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC3_IN1_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC3_IN1_NF_arg.S5, ADC3_IN1_NF_arg.ADC3_IN1_psrc, ADC3_IN1_NF_arg.ADC3_IN1_pdst, ADC3_IN1_NF_arg.ADC3_IN1_Blocksize);
   }




void init_ADC3_IN2_struct(void)
  {
    //Ensure that ADC1_DMA_sort_ptr is initialized
	ADC3_IN2_NF_arg.ADC3_IN2_psrc = (float32_t *)(ADC3_DMA_sort_ptr->ADC3_IN2_bfr);  // Typecasting. Assigned at runtime
  }

void init_ADC3_IN2_FO_biquad_filter(void)
  {
	 arm_biquad_cascade_df2T_init_f32
	 (
	        (arm_biquad_cascade_df2T_instance_f32 *) &ADC3_IN2_NF_arg.S6,  // Pointer to the instance
	        ADC3_IN2_NF_arg.ADC3_IN2_numstages,                                     // Number of stages (2 in this case)
	        ADC3_IN2_NF_arg.ADC3_IN2_pcoeffs,                                       // Pointer to coefficients array
	        ADC3_IN2_NF_arg.ADC3_IN2_pState                                         // Pointer to the state buffer
	 );
  }

void update_ADC3_IN2_FO_biquad_filter(void)
   {
	arm_biquad_cascade_df2T_f32(&ADC3_IN2_NF_arg.S6, ADC3_IN2_NF_arg.ADC3_IN2_psrc, ADC3_IN2_NF_arg.ADC3_IN2_pdst, ADC3_IN2_NF_arg.ADC3_IN2_Blocksize);
   }

