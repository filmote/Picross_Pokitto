#include "TitleScreenState.h"
#include "../images/Images.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;

constexpr const static uint8_t UPLOAD_DELAY = 16;


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void TitleScreenState::activate(StateMachine & machine) {

	(void)machine;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void TitleScreenState::update(StateMachine & machine) {


	// Handle other input ..

	if (PC::buttons.pressed(BTN_A)) {
		machine.changeState(GameStateType::SelectPuzzle); 
	}

}


// ----------------------------------------------------------------------------
//  Render the state .. 
//
void TitleScreenState::render(StateMachine & machine) {

	(void)machine;

    PD::drawBitmap(3, 4, Images::TitleScreen_Top);
	PD::drawBitmap(3, 3, Images::TitleScreen_Top);

	PD::drawBitmap(16, 25, Images::TitleScreen_Middle);

	PD::drawBitmap(27, 45, Images::TitleScreen_Bottom);
	PD::drawBitmap(27, 44, Images::TitleScreen_Bottom);

}
