  #include <Adafruit_GFX.h>
  #include <Adafruit_NeoPixel.h>
  #include <Adafruit_NeoMatrix.h>

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
#define FACTORYRESET_ENABLE     1

#define PIN_MODE_BTN            2
#define PIN_BRIGHT_BTN          3
#define PIN_COLOR_BTN           4
#define PIN_NEO_PIXEL           5   
     
// Example for NeoPixel 8x8 Matrix.  In this application we'd like to use it 
// with the back text positioned along the bottom edge.
// When held that way, the first pixel is at the top left, and 
// lines are arranged in columns, zigzag order.  The 8x8 matrix uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN_NEO_PIXEL,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
/*=========================================================================*/



/** modes:
 *  0 - off
 *  1 - full red square 
 *  2 - full red square blink effect (that changes in intensity)
 *  3 - red circle 
 *  4 - red circle blink effect
 *  5 - changing red squares 
 *  6 - Skull
 *  7 - PacMan
 *  8 - Invader
 *  9 - Christmas tree
 */
int mode = 0; 
int vStep = 0;        // Vertical step for big images
int vMove = 1;        // move right (1) or left (-1)
int brightMin = 5;    // Minimum bright
int brightState = 10; // Current bright status (for effects)
int brightStep = 15;
int brightMax = 255;

uint32_t red = matrix.Color(255, 10, 10);
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
int effect = 0; 
// Numer of updates since last button pressed.
int ticks = 0;

// 
 uint32_t colors[] = {
  matrix.Color(255, 25, 25),    // Red
  matrix.Color(220, 125, 220),  // Pink
  matrix.Color(130, 0, 160),  // Violet
  matrix.Color(40, 120, 220),  // Blue
  matrix.Color(40, 140, 40),  // Green
  matrix.Color(255, 255, 0),  // Yellow
  matrix.Color(200, 200, 200),  // White
 };

void setup(void)
{
  // Matrix initialization
  matrix.begin();
  matrix.setBrightness(brightState);
 
  matrix.fillScreen(0);
  matrix.show(); // This sends the updated pixel colors to the hardware.
  // Other
  pinMode(PIN_MODE_BTN, INPUT);
  pinMode(PIN_BRIGHT_BTN, INPUT);
  pinMode(PIN_COLOR_BTN, INPUT);
  

  Serial.begin(9600);
}

bool checkModeButton(int pin) {
  int buttonState = 0;
  if (ticks < 5) return false;  // Avoid to read twice same button press
  buttonState = digitalRead(pin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ((buttonState == HIGH) && (mode <= 9)) {
    mode++;
    ticks = 0;
    return true;
  } else if ((buttonState == HIGH) && (mode >= 10)){
    // turn LED off:
    mode = 0;
    ticks = 0;
    return true;
  } else {
    // No changes
    return false;
  }
}

bool checkColorButton(int pin) {
  if (ticks < 5) return false;  // Avoid to read twice same button press
  int buttonState = 0;
  Serial.println(sizeof(colors)/4);
  buttonState = digitalRead(pin);
  if (buttonState == HIGH){ 
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
  if (buttonState == HIGH) {
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
    Serial.println("B Max");
    Serial.println(brightMax);
    Serial.println("B Step");
    Serial.println(brightStep);
    ticks = 0;
    return true;
  } else {
    return false;
  }
}

void updateBrightEffect() {
  brightState += brightStep;
  if (brightState >= brightMax) {
    brightState = brightMax;
    brightStep = -1 * brightStep;
  } else if (brightState <= abs(brightMin)) {
    brightState = 5;
    brightStep =  abs(brightStep);
  }
  matrix.setBrightness(brightState);
  Serial.println(brightState);
  matrix.show();
}

void drawPercent(uint32_t c, int cur_val) {
  short indicator_length = 0;
  indicator_length = (short) 8.0 * ((cur_val + 1) * 1.0/ 255.0);
  Serial.println("Indicator:");
  Serial.println(indicator_length);
  if (indicator_length > 0) {
    matrix.drawFastHLine(0, 7, indicator_length, c);
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
  // BikePixel
  const int ROWS = 6;
  const int COLS = 40; 
  uint32_t welcome[ROWS][COLS] = {
    {0,   0,   0,   0, 0,      0, 0,      0,      0,      0, 0,     0,     0,     0, 0, 0,    0,    0,    0, 0,    0, 0,      0,      0,      0, 0,      0,      0,      0, 0,      0,      0,   red, white, 0,     0,     0,      red,   red, 0},                    
    {red, red, red, 0, orange, 0, yellow, 0,      0,      0, 0,     0,     0,     0, 0, tree, tree, tree, 0, blue, 0, 0,      0,      0,      0, 0,      0,      0,      0, purple, 0,      0,   0,   white, white, white, white,  white, 0,   0},
    {red, 0,   red, 0, 0     , 0, yellow, 0,      0,      0, 0,     green, green, 0, 0, tree, 0,    tree, 0, 0,    0, 0,      0,      0,      0, 0,      violet, violet, 0, purple, 0,      0,   red, red,   0,     0,     0,      red,   red, 0},
    {red, red, red, 0, orange, 0, yellow, 0,      yellow, 0, green, green, green, 0, 0, tree, tree, tree, 0, blue, 0, marine, 0,      marine, 0, violet, violet, violet, 0, purple, 0,      red, 0,   0,     red,   0,     red,    0,     0,   red},
    {red, 0,   red, 0, orange, 0, yellow, yellow, 0,      0, green, 0,     0,     0, 0, tree, 0,    0,    0, blue, 0, 0,      marine, 0,      0, violet, 0,      0,      0, purple, 0,      red, 0,   0,     red,   0,     red,    0,     0,   red},
    {red, red, red, 0, orange, 0, yellow, 0     , yellow, 0, 0    , green, green, 0, 0, tree, 0,    0,    0, blue, 0, marine, 0,      marine, 0, 0,      violet, violet, 0, purple, purple, 0,   red, red,   0,     0,     0,      red,   red, 0}   
  };
  
  for (int nr = 0; nr < ROWS; nr++) {
    for (int nc = 0 + step; nc < max(8 + step, COLS); nc++) {
      matrix.drawPixel(nc - step, nr, welcome[nr][nc]);  
    }
  }

  if (step > COLS - 8) {
    vMove = -1;
    delay(500);
  }

  drawPercent(red, brightMax);
}

void drawDot(uint32_t c) {  
  matrix.fillCircle(4, 4, 3, c);
}

void drawInvader(uint32_t c) {
  matrix.drawPixel(1, 0, c);        
  matrix.drawPixel(6, 0, c);
  matrix.drawFastHLine(2, 1, 4, c);
  matrix.drawFastHLine(1, 2, 6, c);
  matrix.drawFastHLine(0, 3, 2, c);
  matrix.drawFastHLine(3, 3, 2, c);
  matrix.drawFastHLine(6, 3, 2, c);
  matrix.drawFastHLine(1, 4, 6, c);
  matrix.drawPixel(1, 5, c);        
  matrix.drawPixel(6, 5, c);
  matrix.drawPixel(2, 6, c);        
  matrix.drawPixel(5, 6, c);
}

void drawChristmasTree(uint32_t c_tree, uint32_t c_dec) {
  matrix.drawFastHLine(3, 0, 2, matrix.Color(255, 255, 0)); // Yellow star
  // Tree
  matrix.drawFastHLine(3, 1, 2, c_tree);
  matrix.drawFastHLine(2, 2, 4, c_tree);
  matrix.drawFastHLine(2, 3, 4, c_tree);
  matrix.drawFastHLine(1, 4, 6, c_tree);
  matrix.drawFastHLine(1, 5, 6, c_tree);
  matrix.drawFastHLine(0, 6, 8, c_tree);
  // Trunk
  matrix.drawFastHLine(3, 7, 2, matrix.Color(180, 130, 0));
  // Decorations
  matrix.drawPixel(3, 3, c_dec);
  matrix.drawPixel(5, 4, c_dec);
  matrix.drawPixel(2, 5, c_dec);
}

void drawSkull(uint32_t c) {
  matrix.drawFastHLine(1, 0, 6, c);
  matrix.drawFastHLine(1, 1, 6, c);
  matrix.drawFastVLine(0, 1, 4, c);
  matrix.drawFastVLine(7, 1, 4, c);
  matrix.drawFastHLine(3, 2, 2, c);
  matrix.drawFastHLine(2, 3, 4, c);
  matrix.drawFastHLine(1, 4, 6, c);
  matrix.drawFastHLine(1, 5, 6, c);
  matrix.drawPixel(2, 6, c);
  matrix.drawPixel(5, 6, c);
  matrix.drawFastHLine(2, 7, 4, c);
}

void drawHeart(uint32_t c) {
  matrix.drawFastHLine(1, 1, 2, c);
  matrix.drawFastHLine(4, 1, 2, c);
  matrix.drawFastHLine(0, 2, 7, c);
  matrix.drawFastHLine(0, 3, 7, c);
  matrix.drawFastHLine(1, 4, 5, c);
  matrix.drawFastHLine(2, 5, 3, c);
  matrix.drawPixel(3, 6, c); 
}

void drawMode(int mode_id, uint32_t c) {
   matrix.setBrightness(brightMax);
   if (mode == 0) {
      drawWelcome(vStep);
    } else if ((mode == 1) || (mode == 2)) {  // Big square and blinking one
      matrix.fillScreen(c);
    } else if ((mode == 3) || (mode == 4)) {  // Circle and blinking circle
      matrix.fillScreen(0);
      drawDot(c);
    } else if ((mode == 5) || (mode == 6)) {  // Heart and blinking heart
      matrix.fillScreen(0);
      drawHeart(c);
    } else if (mode == 7) { // Scull
      matrix.fillScreen(0);
      drawSkull(c);
    } else if (mode == 8) { // Space invader
      matrix.fillScreen(0);
      drawInvader(c);
    } else if (mode == 9) { // Tree
      matrix.fillScreen(0);
      drawChristmasTree(matrix.Color(50, 140, 50), c);
    }
    matrix.show(); // Sends the updated pixel colors to the hardware.
}
    
void loop() {
  if (checkModeButton(PIN_MODE_BTN)) {
    drawMode(mode, colors[colorIndex]);
    delay(100);
  }
  if (checkColorButton(PIN_COLOR_BTN)) {
    drawMode(mode, colors[colorIndex]);
    delay(100);
  }
  // Setup bright only on 0 mode
  if ((mode == 0) && checkBrightButton(PIN_BRIGHT_BTN)) {
    matrix.setBrightness(brightMax);
    delay(50);
  } else {
    // Update blinking effect
    if ((mode == 2) || (mode == 4) || (mode == 6)) {
      updateBrightEffect();
      delay(50);
    }
    if (mode == 0) {
      drawMode(mode, colors[colorIndex]);
      delay(100);
      vStep += vMove;
    }
  }
  // To avoid duplicate operations
  if (ticks < 100) {
    ticks += 1;
    delay(25);
  }
}
