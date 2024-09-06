/**
 * ADCC Spike Detection - Polling Example Driver File
 * 
 * @file adcc_example.c
 * 
 * @addtogroup adcc_example
 * 
 * @brief This is the generated example implementation for ADCC Spike Detection - Polled driver.
 *
 * @version ADCC Spike Detection - Polled Example Version 1.0.0
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/* Use Case 3 - Polled implementation. Copy this code to your project source, e.g., to main.c  */
/* ------------------------------------------------------------------

#include "mcc_generated_files/system/system.h"

static void Timer_Callback_100ms(void);

static const struct TMR_INTERFACE *Timer = &TimerX; // TODO: Replace TimerX with name of const struct TMR_INTERFACE, from MCC Generated Files > timer > tmrx.c
static volatile bool sendFrame = false;

void Timer_Callback_100ms(void)
{
    ADCC_DischargeSampleCapacitor();
    DataStreamer.adcResult = ADCC_GetSingleConversion(channel_ANAx); // TODO: Replace with the ADCC Channel you selected in Pin Grid View

   //TODO: Replace all "PIR2bits" with "PIR1bits" when K83 or K42 devices are used
    if (PIR2bits.ADTIF != 0) // Check Threshold interrupt flag, (first enable Threshold interrupts and look at ISR)
    {
        PIR2bits.ADTIF = 0; //Clear interrupt flag
        DataStreamer.adcResult_lastSpike = ADCC_GetConversionResult();
        DataStreamer.adcSpikeCount++;
        IO_LED_Toggle();
        IO_Debug_Toggle();
    }
    WriteFrame();
}


int main(void)
{
    SYSTEM_Initialize();

    DataStreamer.adcResult_lastSpike = 0;
    DataStreamer.adcResult = 0;
    DataStreamer.adcSpikeCount = 0;

    Timer->TimeoutCallbackRegister(Timer_Callback_100ms);

    while (1)
    {
        Timer->Tasks();
    }
}
------------------------------------------------------------------ */
/**
 End of File
*/