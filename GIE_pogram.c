/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : GIE DRIVER    *************************************************************************************************************/
/************************************************* BY      : Youssef Ayman *************************************************************************************************************/
/************************************************* Date    : 27Aug20       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/

# include "STD_TYPES.h"
# include "BIT_MATH.h"
# include "GIE_private.h"
# include "GIE_config.h"



void GIE_VidEnable (void)
{
	SET_BIT(EXTI_SREG,SREG_I);
	
}


void GIE_VidDisable (void)
{
	CLR_BIT(EXTI_SREG,SREG_I);
	
}
