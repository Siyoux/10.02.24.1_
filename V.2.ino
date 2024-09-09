#include <MD_Parola.h> // Library Animasi
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4 // Jumlah LED matrix
#define CS_PIN 3
int S = 0;
#define DATA_PIN 11
#define CLK_PIN 13
MD_Parola mx = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Walker Sprite (Animasi orang berjalan)
const uint8_t A_WALKER = 5;
const uint8_t B_WALKER = 7;
const uint8_t PROGMEM walker[A_WALKER * B_WALKER] =  
{
  0x00, 0x48, 0x77, 0x1f, 0x1c, 0x94, 0x68,
  0x00, 0x90, 0xee, 0x3e, 0x38, 0x28, 0xd0,
  0x00, 0x00, 0xae, 0xfe, 0x38, 0x28, 0x40,
  0x00, 0x00, 0x2e, 0xbe, 0xf8, 0x00, 0x00,
  0x00, 0x10, 0x6e, 0x3e, 0xb8, 0xe8, 0x00,
};

void setup() {
  // Inisialisasi LED Matrix
  mx.begin();
  mx.setIntensity(10); // Mengatur kecerahan (0-15)
  mx.displayClear();    // Membersihkan layar
  mx.displayText("HALLO", PA_CENTER, 100, 100, PA_SCROLL_UP_LEFT, PA_SCROLL_DOWN_LEFT); 
}

void loop() {
  // Ganti animasi atau teks sesuai dengan nilai S
  switch (S) {
    case 0:
      if (mx.displayAnimate()) {
        mx.displayClear();
        mx.setSpriteData(walker, A_WALKER, B_WALKER, walker, A_WALKER, B_WALKER);
        mx.displayText("Welcome", PA_CENTER, 45, 100, PA_SPRITE, PA_SPRITE);
        mx.displayReset(); 
        S++;  // Pindah ke case berikutnya
      }
      break;

    case 1:
      if (mx.displayAnimate()) {
        mx.displayText("Siyoux", PA_CENTER, 100, 100, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
        mx.displayReset();
        S++;
      }
      break;

    case 2:
      if (mx.displayAnimate()) {  
        mx.displayClear();
        mx.displayText("Siyoux", PA_CENTER, 45, 100, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        mx.displayReset();
        S++;
      }
      break;

    case 3:
      if (mx.displayAnimate()) {
        mx.displayText("Siyoux", PA_CENTER, 100, 100, PA_RANDOM, PA_RANDOM);
        mx.displayReset();
        S++;
      }
      break;

    case 4:
      if (mx.displayAnimate()) {
        mx.displayClear();
        mx.displayText("Siyoux", PA_CENTER, 45, 100, PA_SLICE, PA_SLICE);
        mx.displayReset();
        S++;
      }
      break;

    case 5:
      if (mx.displayAnimate()) {
        mx.displayClear();
        mx.displayText("Siyoux", PA_CENTER, 45, 100, PA_RANDOM, PA_RANDOM);
        mx.displayReset();
        S = 0;  // Kembali ke case 0 untuk looping
      }
      break;

    default:
      break;
  }
}
