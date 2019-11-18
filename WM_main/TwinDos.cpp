/*******************************************************************************
@Module         Twin Dos
--------------------------------------------------------------------------------
@Filename       TwinDos.cpp
--------------------------------------------------------------------------------
@Description    check in header file for more details

--------------------------------------------------------------------------------
@Author         Iulian G.,  Bogdan Calinoiu
@Date           14.11.2018, 22.04.2018

@Copyright      Miele  Cie Copyright 2018

*******************************************************************************/


/*******************************************************************************
@Project Includes
*******************************************************************************/
#include "TwinDos.h"

/*******************************************************************************
@Constants (global)
*******************************************************************************/

/*******************************************************************************
@Macros (global)
*******************************************************************************/

/*******************************************************************************
@Type definitions  (global)
*******************************************************************************/

/*******************************************************************************
@Local Variables 
*******************************************************************************/

/*******************************************************************************
@External Prototypes
*******************************************************************************/

/*******************************************************************************
@Prototypes local Functions
*******************************************************************************/

/*******************************************************************************
Function description and additional notes,
are given at the function prototype in the header file
*******************************************************************************/
TwinDos::TwinDos()
{
    this->m_InputPin_u8 = 0;
    this->m_InitFlag_b = false;
}

/*******************************************************************************
Function description and additional notes,
are given at the function prototype in the header file
*******************************************************************************/
bool TwinDos::Initialise_e(uint8_t pin_u8)
{        
    if(m_InitFlag_b == false)
    {
        this->m_InputPin_u8 = pin_u8;
        pinMode(this->m_InputPin_u8, INPUT_PULLDOWN);

        this->m_InitFlag_b = true;    
    }
    return this->m_InitFlag_b;
}

/*******************************************************************************
Function description and additional notes,
are given at the function prototype in the header file
*******************************************************************************/
bool TwinDos::isPresent_b()
{    
    // "!" because when pressed they will connected to ground, their value will be "0", so: if(false && false)   esti prost 
    return digitalRead(this->m_InputPin_u8);
}
