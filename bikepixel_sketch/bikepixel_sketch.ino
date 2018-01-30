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

#define PIN                     6   // Which pin on the Arduino is connected to the NeoPixels?
     
// Example for NeoPixel 8x8 Matrix.  In this application we'd like to use it 
// with the back text positioned along the bottom edge.
// When held that way, the first pixel is at the top left, and
// lines are arranged in columns, zigzag order.  The 8x8 matrix uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
/*=========================================================================*/

const int PIN_MODE_BTN = 2;
const int PIN_ADD_BRG_BTN = 3;
const int PIN_REM_BRG_BTN = 4;

/** modes:
 *  0 - off
 *  1 - full red square 
 *  2 - full red square blink effect (that changes in intensity)
 *  3 - red circle 
 *  4 - red circle blink effect
 *  5 - changing red squares 
 *  
 *  
 *  8 - Invader
 *  9 - Christmas tree
 */
int mode = 0;
int buttonState = 0; 
int brightState = 10;
int brightStep = 2;
int brightMax = 50;

void setup(void)
{
  // Matrix initialization
  matrix.begin();
  matrix.setBrightness(brightState);
 
  matrix.fillScreen(0);
  matrix.show(); // This sends the updated pixel colors to the hardware.
  // Other
  pinMode(PIN_MODE_BTN, INPUT);
}

bool checkModeButton(int pin) {
  buttonState = digitalRead(pin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if ((buttonState == HIGH) && (mode <= 9)) {
    mode++;
    return true;
  } else if ((buttonState == HIGH) && (mode >= 10)){
    // turn LED off:
    mode = 0;
    return true;
  } else {
    // No changes
    return false;
  }
}

void updateBrightEffect() {
  brightState += brightStep;
  if (brightState >= brightMax) {
    brightState = brightMax;
    brightStep = -2;
  } else if (brightState <= 2) {
    brightState = 2;
    brightStep = 2;
  }
  matrix.setBrightness(brightState);
  matrix.show();
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
    
void loop() {
  if (checkModeButton(PIN_MODE_BTN)) {
    if (mode == 0) {
      matrix.fillScreen(0);
    } else if ((mode == 1) || (mode == 2)) {
      matrix.fillScreen(matrix.Color(255, 0, 0));
    } else if (mode == 7) {
      
    } else if (mode == 8) {
      matrix.fillScreen(0);
      drawInvader(matrix.Color(180, 0, 255));
    } else if (mode == 9) {
      matrix.fillScreen(0);
      drawChristmasTree(matrix.Color(50, 140, 50), matrix.Color(200, 55, 55));
    }
    matrix.show(); // Sends the updated pixel colors to the hardware.
    delay(100);
  }
  if (mode == 2) {
    updateBrightEffect();
    delay(50);
  }
}
