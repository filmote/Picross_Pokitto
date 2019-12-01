#include "SplashScreenState.h"
#include "../images/Images.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void SplashScreenState::activate(StateMachine & machine) {

  (void)machine;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void SplashScreenState::update(StateMachine & machine) { 

  auto justPressed = PC::buttons.pressed(BTN_A);

    if (justPressed > 0 && this->counter > 0) {

        this->counter = 124;

    }

    if (justPressed > 0 && this->counter == 0) {

        this->counter = 1;

//    TCCR3A = _BV(COM3A0); // set toggle on compare mode (which connects the pin)
//    OCR3A = 3905; // 128 Hz

    }

    if (this->counter > 0) {

        this->counter++;

        switch (this->counter) {

            case 2:     
//        OCR3A = 18000;    
                break;

            case 5:     
//        TCCR3A = 0;       
                break;
        
            case 125:   
                machine.changeState(GameStateType::TitleScreen);    
                break;

            default:
                break;

        }

    }

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void SplashScreenState::render(StateMachine & machine) {

    PD::drawBitmap(47, 17, Images::Ppot_Buttons);
    PD::drawBitmap(43, 26, Images::Ppot_ButtonUp);
    PD::drawBitmap(73, 26, Images::Ppot_ButtonUp);

    if (counter == 0) {

        PD::drawBitmap(58, 26, Images::Ppot_ButtonUp);
        PD::drawBitmap(26, 46, Images::Ppot_Caption);

    }
    else {

        PD::drawBitmap(58, 26, Images::Ppot_ButtonDown);
        PD::drawBitmap(44, 46, Images::Ppot_Loading);

        uint8_t i = (counter / 15) % 4;

        for (uint8_t j = 0; j < i; j++) {

            PD::drawPixel(79 + (j * 2), 49);

        }

    }

}
