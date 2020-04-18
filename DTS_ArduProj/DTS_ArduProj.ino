/*
 Name:		DTS_ArduProj.ino
 Created:	10.04.2020 19:23:33
 Author:	jowan
*/



#include <GxEPD.h>
#include <GxFont_GFX.h>
#include <GxGDEW075Z09/GxGDEW075Z09.h>    // 7.5" b/w/r

#include GxEPD_BitmapExamples

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#if defined(ESP32)

// for SPI pin definitions see e.g.:
// C:\Users\xxx\Documents\Arduino\hardware\espressif\esp32\variants\lolin32\pins_arduino.h

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4
#endif


void setup()
{
    Serial.begin(115200);
    //Serial.println();
    Serial.println("setup");
    pinMode(2, OUTPUT);

    display.init(115200);
    display.setTextColor(GxEPD_BLACK);
    
    //display.println("Kallao");
    display.println();
    Serial.println("setup done");
}

void loop()
{

    display.setCursor(0, 1);
    display.println(analogRead(0));
    display.println(".....");
    //display.update();
    digitalWrite(2, HIGH);
    delay(0);
    digitalWrite(2, LOW);
    delay(0);

    /*display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(0, 0);
    display.startWrite();
    display.printf("Jwoan");
    display.println("Halllo test");
    display.println("Jwoan Halllo");
    display.println("Halllo test");
    display.println("Jwoan test");
    display.println("Jwoan test");
    display.println("Jwoan test");
    display.println("Jwoan test");
    display.println("Jwoan test");
    delay(2);*/
    //showFont("Jowan ist ein Cooler Typ, und das ist war");
    //delay(0);
//#if !defined(__AVR)
    //showFont("Jowan", &FreeMonoBold9pt7b);
    //showFont("FreeMonoBold12pt7b", &FreeMonoBold12pt7b);
//#else
//    display.drawCornerTest();
//    delay(2000);
//    display.drawPaged(showFontCallback);
//#endif
    //delay(0);
}
//
//#if defined(_GxGDEW075Z09_H_)
//#define HAS_RED_COLOR
void showBitmapExample(const uint8_t *bitmap)
{

    display.drawExampleBitmap(bitmap, sizeof(bitmap));
    delay(2000);
    display.drawExampleBitmap(bitmap, sizeof(bitmap));
    delay(2000);
    display.setRotation(0);
    display.fillScreen(GxEPD_WHITE);
    display.drawExampleBitmap(bitmap, 0, 0, 0, 0, GxEPD_BLACK);
    display.update();
    delay(2000);

}



void showFont(const char name[])
{
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    display.setTextSize(160, 110);
    display.setFont();
    display.setCursor(30, 40);
    display.println();
    display.println(name);

#if defined(HAS_RED_COLOR)
    display.setTextColor(GxEPD_RED);
#endif
    display.update();
    delay(0);
}


//void showFont(const char name[], const GFXfont* f)
//{
//    display.fillScreen(GxEPD_WHITE);
//
//    display.setTextColor(GxEPD_BLACK);
//    display.setFont(f);
//    display.setCursor(0, 0);
//    display.println();
//    display.println(name);
//    //display.println("ShowFont - Jowan");
//    //display.println("017632429115");
//    //display.println("@Kiel");
//
//#if defined(HAS_RED_COLOR)
//    display.setTextColor(GxEPD_RED);
//#endif
//    /* display.println("Farbig");
//     display.println("pqrstuvwxyz{|}~ ");*/
//    display.update();
//    delay(0);
//}

void showFontCallback()
{
    const char* name = "JOwanTEst";
    const GFXfont* f = &FreeMonoBold9pt7b;
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(f);
    display.setCursor(0, 0);
    display.println();
    display.println(name);
    display.println(" Zeichen");
    display.println("JOwan");
    display.println("JOwan TEst");
    display.println("JOwan TEst");
#if defined(HAS_RED_COLOR)
    display.setTextColor(GxEPD_RED);
#endif
    display.println("Hallo");
    display.println("JowanSulaiman");
}

void drawCornerTest()
{
    display.drawCornerTest();
    delay(5000);
    uint8_t rotation = display.getRotation();
    for (uint16_t r = 0; r < 4; r++)
    {
        display.setRotation(r);
        display.fillScreen(GxEPD_WHITE);
        display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
        display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_RED);
        display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_RED);
        display.fillRect(0, display.height() - 33, 32, 32, GxEPD_RED);
        display.update();
        delay(5000);
    }
    display.setRotation(rotation); // restore
}
