#include <SD_card_logger.h>
// ---------------------------- here you can check how to connect SD card reader to Arduino---------------------------------------

//       https://lastminuteengineers.com/arduino-micro-sd-card-module-tutorial/

// ---------------------------- here you can check how to connect SD card reader to Arduino---------------------------------------

// in order to log to SD you need my Simpletimer library https://github.com/natnqweb/Simpletimer
Simpletimer timer1{};
char buffer[30]{};
static const uint8_t CS = 10; // micro SD CS pin by default it is 10
int i{ 0 };
sd_card_logger logger1("XY.txt", CS);// create object
void setup()
{// this is first line created in file
    logger1.init("X X^2");
    //you can provide empty string if you want
}
void loop()
{
    if (timer1.timer(999))// entry every 999 ms
    {
        i++;
        sprintf(buffer, "%d %d\n", i, i * i);
    }

    logger1.log(buffer, 1000);//logg buffer every 1 s
}