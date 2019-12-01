#pragma once

#include "Pokitto.h"
#include <stdint.h>
#include <stddef.h>


using PC = Pokitto::Core;
using PD = Pokitto::Display;


// ----------------------------------------------------------------------------
//  A better absolute as it uses less memory than the standard one .. 
//
template<typename T> T absT(const T & v) {
  
  return (v < 0) ? -v : v;

}

// This gets the length of an array at compile time
template< typename T, size_t N > constexpr size_t ArrayLength(T (&)[N]) {
	return N;
}


static inline uint16_t getFrameCount() {

    return Pokitto::Core::frameCount;

}

static inline uint8_t getFrameCount(uint8_t mod) {

    return (Pokitto::Core::frameCount % mod);

}

static inline bool getFrameCountHalf(uint8_t mod) {

    return ((Pokitto::Core::frameCount % mod) > (mod /2));

}

static inline bool isFrameCount(uint8_t mod) {

    return ((Pokitto::Core::frameCount % mod) == 0);

}

static inline bool isFrameCount(uint8_t mod, uint8_t val) {
    
    return ((Pokitto::Core::frameCount % mod) == val);

}


static inline void drawDottedColumn(uint8_t x, uint8_t sy, uint8_t ey) {
    
    for (uint8_t y = sy; y <= ey; y = y + 2) {
        
        PD::drawPixel(x, y);
    }

}

static inline void drawDottedRow(uint8_t sx, uint8_t ex, uint8_t y) {
    
    for (uint8_t x = sx; x <= ex; x = x + 2) {
        
        PD::drawPixel(x, y);
    }

}
