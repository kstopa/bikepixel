#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

#define DEBUG                   true

// PINs definitions
#define PIN_BATT_STATUS         A0
#define PIN_MODE_BTN            3
#define PIN_EFFECT_BTN          4
#define PIN_COLOR_BTN           5
#define PIN_NEO_PIXEL           6


#define VMIN      3.6
/*=========================================================================
APPLICATION SETTINGS
                          
MATRIX DECLARATION        Parameter 1 = width of NeoPixel matrix
                          Parameter 2 = height of matrix
                          Parameter 3 = pin number (most are valid)
                          Parameter 4 = matrix layout flags, add together as needed:
NEO_MATRIX_TOP,
NEO_MATRIX_BOTTOM,
NEO_MATRIX_LEFT,
NEO_MATRIX_RIGHT          Position of the FIRST LED in the matrix; pick two, e.g.
                          NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
                          NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
                          rows or in vertical columns, respectively; pick one or the other.
NEO_MATRIX_PROGRESSIVE,
NEO_MATRIX_ZIGZAG         all rows/columns proceed in the same order, 
                          or alternate lines reverse direction; pick one.

                          See example below for these values in action.

Parameter 5 = pixel type flags, add together as needed:
                          
NEO_KHZ800                800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
NEO_KHZ400                400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
NEO_GRB                   Pixels are wired for GRB bitstream (most NeoPixel products)
NEO_RGB                   Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
-----------------------------------------------------------------------*/
 
// NeoPixel 8x8 Matrix.  In this application we'd like to use it 
// with the back text positioned along the bottom edge.
// When held that way, the first pixel is at the top left, and 
// lines are arranged in columns, zigzag order.  The 8x8 matrix uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 5, PIN_NEO_PIXEL,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
/*=========================================================================*/



/** modes:
 *  0 - Bike Pixel logo welcome 
 *  1 - full red square 
 *  
 */
byte mode = 1; 
byte effect = 1;
int vStep = 0;        // Vertical step for big images
int vMove = 1;        // move right (1) or left (-1)
int brightMin = 5;    // Minimum bright
int brightState = 40; // Current bright status (for effects)
int brightStep = 15;
int brightMax = 250;

uint32_t red = matrix.Color(255, 20, 20);
uint32_t orange = matrix.Color(253, 138, 59);
uint32_t yellow = matrix.Color(249, 233, 63);
uint32_t green = matrix.Color(161, 237, 45);
uint32_t tree = matrix.Color(26, 174, 67);
uint32_t blue = matrix.Color(20, 85, 75);
uint32_t marine = matrix.Color(11, 81, 190);
uint32_t violet = matrix.Color(210, 47, 210);
uint32_t purple = matrix.Color(120, 20, 150); 
uint32_t white = matrix.Color(200, 200, 200); 
int colorIndex = 0;
// Numer of updates since last button pressed.
int ticks = 0;

// 
 uint32_t colors[] = {
  red,
  matrix.Color(220, 125, 220),  // Pink
  matrix.Color(130, 0, 160),  // Violet
  matrix.Color(40, 120, 220),  // Blue
  matrix.Color(40, 140, 40),  // Green
  matrix.Color(255, 255, 0),  // Yellow
  matrix.Color(200, 200, 200),  // White
 };
// Battery voltage

float vBat = 4.2;
 
// Welcome Bike Pixels moveing logo
const int BP_ROWS = 6;
const int BP_COLS = 40; 
const uint32_t welcome[BP_ROWS][BP_COLS] = {
  {0,   0,   0,   0, 0,      0, 0,      0,      0,      0, 0,     0,     0,     0, 0, 0,    0,    0,    0, 0,    0, 0,      0,      0,      0, 0,      0,      0,      0, 0,      0,      0,   red, white, 0,     0,     0,      red,   red, 0},                    
  {red, red, red, 0, orange, 0, yellow, 0,      0,      0, 0,     0,     0,     0, 0, tree, tree, tree, 0, blue, 0, 0,      0,      0,      0, 0,      0,      0,      0, purple, 0,      0,   0,   white, white, white, white,  white, 0,   0},
  {red, 0,   red, 0, 0     , 0, yellow, 0,      0,      0, 0,     green, green, 0, 0, tree, 0,    tree, 0, 0,    0, 0,      0,      0,      0, 0,      violet, violet, 0, purple, 0,      0,   red, red,   0,     0,     0,      red,   red, 0},
  {red, red, red, 0, orange, 0, yellow, 0,      yellow, 0, green, green, green, 0, 0, tree, tree, tree, 0, blue, 0, marine, 0,      marine, 0, violet, violet, violet, 0, purple, 0,      red, 0,   0,     red,   0,     red,    0,     0,   red},
  {red, 0,   red, 0, orange, 0, yellow, yellow, 0,      0, green, 0,     0,     0, 0, tree, 0,    0,    0, blue, 0, 0,      marine, 0,      0, violet, 0,      0,      0, purple, 0,      red, 0,   0,     red,   0,     red,    0,     0,   red},
  {red, red, red, 0, orange, 0, yellow, 0     , yellow, 0, 0    , green, green, 0, 0, tree, 0,    0,    0, blue, 0, marine, 0,      marine, 0, 0,      violet, violet, 0, purple, purple, 0,   red, red,   0,     0,     0,      red,   red, 0}   
};

void setup(void)
{
  // Matrix initialization
  matrix.begin();
  matrix.setBrightness(brightState);
  matrix.fillScreen(0);
  matrix.show(); // This sends the updated pixel colors to the hardware.
  drawMode(colors[colorIndex]);
  // PINs setup
  pinMode(PIN_MODE_BTN, INPUT);
  pinMode(PIN_EFFECT_BTN, INPUT);
  pinMode(PIN_COLOR_BTN, INPUT);
  if (DEBUG) {
    Serial.begin(9600);
  }
}

bool checkModeButton(int pin) {
  int buttonState = 0;
  bool changed = false;
  if (ticks < 5) return false;  // Avoid to read twice same button press
  buttonState = digitalRead(pin);
  // Check if the pushbutton is pressed. If it is, the buttonState is LOW as they are pulled up
  if ((buttonState == LOW) && (mode <= 11)) {
    mode++;
    ticks = 0;
    changed = true;
  } else if ((buttonState == LOW) && (mode >= 10)){
    // turn LED off:
    mode = 0;
    ticks = 0;
    changed = true;
  }
  if (DEBUG) {
    Serial.print("Mode: ");
    Serial.println(mode);
  }
  return changed;
}

bool checkColorButton(int pin) {
  if (ticks < 5) return false;  // Avoid to read twice same button press
  int buttonState = 0;
  buttonState = digitalRead(pin);
  if (buttonState == LOW){ 
    if (colorIndex + 1 < sizeof(colors)/4) {
      colorIndex++;
    } else {
      colorIndex = 0;
    }
    ticks = 0;
    return true;
  }
  return false;
}

bool checkBrightButton(int pin) {
  int buttonState = 0;
  if (ticks < 5) return false;  // Avoid to read twice same button press
  buttonState = digitalRead(pin);
  if (buttonState == LOW) {
    brightMax += 32;
    if (brightMax > 255) {
      brightMax = 31;
      brightStep = 2;
    } else {
      if (brightMax < 20) {
        brightStep = 2;
      } else if (brightMax < 50) {
        brightStep = 3;
      } else if (brightMax < 100) {
        brightStep = 7;
      } else {
        brightStep = 15;
      }
    }
    if (DEBUG) {
      Serial.println("B Max");
      Serial.println(brightMax);
      Serial.println("B Step");
      Serial.println(brightStep);
    }
    ticks = 0;
    return true;
  }
  return false;
}

float checkBatteryStatus() {
  vBat = float(analogRead(PIN_BATT_STATUS));
  vBat = 5.0*vBat/1024.0;      // Convert to voltage note that vcc (5V) is divided by 2
  if (DEBUG) {
    Serial.println("Vcc");
    Serial.println(vBat);
  }
  return vBat;
}

bool checkEffectButton() {
  if (ticks < 5) return false;  // Avoid to read twice same button press
  if (digitalRead(PIN_EFFECT_BTN) == LOW) {
    brightState = brightMin;
    if (effect == 2) {
      effect = 0;   // back to static icon
      matrix.setBrightness(brightMax);
      matrix.show();
    } else {
      effect += 1;
    }
    if (DEBUG) {
      Serial.print("Effect: ");
      Serial.println(effect);
    }
    ticks = 0;
    return true;
  }
  return false;
}

// Update fade out effect
void updateEffectFadeOut() {
  brightState += brightStep;
  ticks += 1;
  if (brightState >= brightMax) {
    brightState = brightMax;
    brightStep = -1 * brightStep;
  } else if (brightState <= abs(brightMin)) {
    ticks = 0;
    brightState = 5;
    brightStep =  abs(brightStep);
  }
  matrix.setBrightness(brightState);
  matrix.show();
}

void updateEffectBlink() {
  if (brightState < brightMax) {
    brightState = brightMax;
  } else {
    brightState = brightMin;
  }
  delay(50);
  matrix.setBrightness(brightState);
  matrix.show();
}

void drawPercent(uint32_t c, int cur_val, float max_value, int row) {
  short indicator_length = 0;
  indicator_length = (short) 5.0 * ((cur_val + 1) * 1.0/ max_value);
  if (indicator_length > 0) {
    matrix.drawFastHLine(0, row, indicator_length, c);
  }
}

/**
 * Draw welcome message with along with the brightness setup.
 */
void drawWelcome(int step) {
  step = ceil(step / 1);
  if (step < 0) {
    vMove = 1;
    step = 0;
  }
  matrix.fillScreen(0);
  for (int nr = 0; nr < BP_ROWS; nr++) {
    for (int nc = 0 + step; nc < max(8 + step, BP_COLS); nc++) {
      matrix.drawPixel(nc - step, nr, welcome[nr][nc]);  
    }
  }
  if (step > BP_COLS - 8) {
    vMove = -1;
    delay(500);
  }
  drawPercent(white, checkBatteryStatus()-VMIN, 4.2-VMIN, 6);
  drawPercent(red, brightMax, 255.0, 7);
  
}

void drawDot(uint32_t c) {  
  matrix.fillCircle(2, 2, 2, c);
}

void drawRect(uint32_t c) { 
  matrix.drawFastHLine(0, 0, 5, c);
  matrix.drawFastVLine(0, 1, 3, c);
  matrix.drawFastVLine(4, 1, 3, c);
  matrix.drawFastHLine(0, 4, 5, c);
  matrix.drawPixel(2, 2, c);
}

void drawGhost(uint32_t c) {
  matrix.drawFastVLine(0, 1, 4, c);
  matrix.drawPixel(1, 0, c);
  matrix.drawFastVLine(1, 2, 2, c);
  matrix.drawFastVLine(2, 0, 5, c);
  matrix.drawPixel(3, 0, c);
  matrix.drawFastVLine(3, 2, 2, c);
  matrix.drawFastVLine(4, 1, 4, c);
}

void drawSmily(uint32_t c) {
  // Eyes
  matrix.drawPixel(1, 1, c);
  matrix.drawPixel(3, 1, c);
  // Smile
  matrix.drawPixel(0, 3, c);
  matrix.drawPixel(4, 3, c);
  matrix.drawFastHLine(1, 4, 3, c);
}

void drawHeart(uint32_t c) {
  matrix.drawPixel(1, 0, c); 
  matrix.drawPixel(3, 0, c);
  matrix.drawFastHLine(0, 1, 5, c);
  matrix.drawFastHLine(0, 2, 5, c);
  matrix.drawFastHLine(1, 3, 3, c);
  matrix.drawPixel(2, 4, c); 
}

void drawMode(uint32_t c) {
   if (mode == 0) {       // TODO for model M
      drawWelcome(vStep);   
    } else if (mode == 1) {  // Big square
      matrix.fillScreen(c);
    } else if (mode == 2) {  // Circle
      matrix.fillScreen(0);
      drawDot(c);
    } else if (mode == 3) {  // Rect
      matrix.fillScreen(0);
      drawRect(c);
    } else if (mode == 4) {  // Heart 
      matrix.fillScreen(0);
      drawHeart(c);
    } else if (mode == 5) { // Scull
      matrix.fillScreen(0);
      drawHeart(c);
    } else if (mode == 6) { // Scull
      matrix.fillScreen(0);
      drawSmily(c);
    } else if (mode == 7) { // Scull
      matrix.fillScreen(0);
      drawGhost(c);
    }
    if (DEBUG) {
      Serial.print("Draw mode: ");
      Serial.println(mode);
    }
    matrix.show(); // Sends the updated pixel colors to the hardware.
}

void updateEffect() {
  if (effect == 1) {
    updateEffectFadeOut();
  } else if (effect == 2) {
    updateEffectBlink();
  }
}
    
void loop() {
  if (checkModeButton(PIN_MODE_BTN)) {
    drawMode(colors[colorIndex]);
    delay(100);
  }
  if (checkColorButton(PIN_COLOR_BTN)) {
    drawMode(colors[colorIndex]);
    delay(100);
  }
  // Setup bright only on 0 mode
  if (mode == 0) {
    if (checkBrightButton(PIN_EFFECT_BTN)) {
      matrix.setBrightness(brightMax);
      delay(50);
    } else {
      drawMode(colors[colorIndex]);
      delay(100);
      vStep += vMove;
    }
  } else if (checkEffectButton()) {
    updateEffect();
    delay(50);
  } else if (effect > 0) {
    updateEffect();
    if (ticks >= 100) {
      delay(50);
    }
  }
  if (ticks < 100) {
    ticks += 1;
    delay(50);
  }
}
