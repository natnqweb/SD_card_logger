#include <SD_card_logger.h>

File txtFile;    
Simpletimer timer1;// in order to log text to sd you need my Simpletimerlibrary https://github.com/natnqweb/Simpletimer
Simpletimer timer2;
char buffer[30];

int i;
sd_card_logger logger1("XY.txt", &txtFile, &timer1);// send timer and File object to sd_card_logger class;
void setup()
{
    logger1.init("X X^2");
	//you can provide empty string if you want
}
void loop()
{
    if (timer2.timer(999))// entry every 999ms
    {
        i++;
        sprintf(buffer, "%d %d\n", i, i * i);
    }

    logger1.log(buffer, 1000);//logg buffer every 1 s
}
