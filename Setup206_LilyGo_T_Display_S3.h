// Setup for the ESP32 T-Display S3 with ST7789-type TFT (may require setting TFT_MAD_MX writecommand to 0x00 in ST7789_Defines.h if image is mirrored and toggle inversion in User Setup 206)

// ST7789 using 8-bit Parallel

#define USER_SETUP_ID 206

#define ST7789_DRIVER
#define INIT_SEQUENCE_3 // Using this initialisation sequence improves the display image

#define CGRAM_OFFSET
// #define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
#define TFT_RGB_ORDER TFT_BGR // Colour order Blue-Green-Red

//#define TFT_INVERSION_ON
#define TFT_INVERSION_OFF

//#define TFT_PARALLEL_8_BIT

#define TFT_WIDTH 172
#define TFT_HEIGHT 320

//added for display on SPI
#define TFT_MISO -1
#define TFT_MOSI 39
#define TFT_SCLK 38
#define TFT_CS 21
//end added

#define TFT_DC 45 //7
#define TFT_RST 40 //5

#define TFT_WR 8
#define TFT_RD 9

//#define TFT_D0 39
//#define TFT_D1 40
//#define TFT_D2 41
//#define TFT_D3 42
//#define TFT_D4 45
//#define TFT_D5 46
//#define TFT_D6 47
//#define TFT_D7 48

#define TFT_BL 46 //38
#define TFT_BACKLIGHT_ON HIGH

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

//#define SPI_FREQUENCY  27000000
#define SPI_FREQUENCY  40000000

#define SPI_READ_FREQUENCY  6000000 // 6 MHz is the maximum SPI read speed for the ST7789V
