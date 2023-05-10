#pragma once

#include <vector>
#ifndef DSP_H
#define DSP_H
#endif

#include <cmath>

namespace dspheaders {

    inline float clamp(float x, float bot, float top) {
        return fmax(bot, (fmin(x, top)));
    }

    inline float scale(float x, float a, float  b) {
        return (b-a)*x + a;
    }

    inline float dcblock(float x, float xm1, float ym1) {
        return  x - xm1 + 0.995 * ym1;
    }

    inline float mtof(int n, float base = 440.f) {
        return base * pow(2,(n/12));
    }

    // Normalize values to a range of 0.0 - 1.0
    // Useful when using a bipolar LFO to modulate phase in an oscillator. 
    inline void unipolar(float* x, int xLen) {
      float maximum = -MAXFLOAT;
      float minimum = MAXFLOAT;
      for (int i = 0; i < xLen; i++) {
        if (x[i] > maximum) {
          maximum = x[i];
        }
        if (x[i] < minimum) {
          minimum = x[i];
        }
      }
      for (int i = 0; i < xLen; i++) {
        x[i] = (x[i] - minimum) / (maximum - minimum);
      }
    } 
    
} /* namespace dspheaders */
