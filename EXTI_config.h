/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : EXTI DRIVER   *************************************************************************************************************/
/************************************************* BY      : Youssef Ayman *************************************************************************************************************/
/************************************************* Date    : 27Aug20       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/

# ifndef EXTI_CONFIG_H
# define EXTI_CONFIG_H

/*SENSE_CONTROL Options :
							1- LOW_LEVEL
							2- ON_CHANGE
							3- FALLING_EDGE
							4- RISING_EDGE			*/

# define INT0_SENSE        		RISING_EDGE
# define INT1_SENSE        		FALLING_EDGE
# define INT2_SENSE        		FALLING_EDGE


/*INITIAL_STATE Options :
							1- ENABLED
							2- DISABLED				*/

# define INT0_INITIAL_STATE        ENABLED
# define INT1_INITIAL_STATE        ENABLED
# define INT2_INITIAL_STATE        ENABLED


#endif
