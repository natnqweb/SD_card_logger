#include <SD_card_logger.h>
// ---------------------------- here you can check how to connect SD card reader to Arduino---------------------------------------

//       https://lastminuteengineers.com/arduino-micro-sd-card-module-tutorial/

// ---------------------------- here you can check how to connect SD card reader to Arduino---------------------------------------

// in order to log to SD you need my Simpletimer library https://github.com/natnqweb/Simpletimer

char buffer[30]{};
static const uint8_t CS = 10; // micro SD CS pin by default it is 10
unsigned long i{ 0 };
sd_card_logger logger("XY.txt", CS);// create object

void UpdateBuffer()
{
    i++;
    sprintf(buffer, "%lu %lu\n", i, (unsigned long)(i * i));
}

void setup()
{
    // this is first line created in file
    //you can provide empty string if you want
    logger.init("X X^2");

    UpdateBuffer();
}
void loop()
{
    if (logger.log(buffer, 1000))// log buffer every 1s after log update buffer
    {
        UpdateBuffer();
    }
}