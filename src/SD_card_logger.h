#ifndef SD_CARD_LOGGER_H
#define SD_CARD_LOGGER_H
#include <Arduino.h>
#include <SD.h>
#include <Simpletimer.h>

class sd_card_logger
{
public:
    String _filename;

    int logging_freq;
    String logmessage;
    String _bootmessage;
    sd_card_logger(String filename, File *file, Simpletimer *timer)
    {
        _filename = filename;
        _file = file;
        _timer = timer;
    }
    void init(String bootmessage);
    bool log(String logmessage, int logging_freq);

private:
    Simpletimer *_timer;
    File *_file;

protected:
    unsigned long lastMillis = 0;
};

#endif