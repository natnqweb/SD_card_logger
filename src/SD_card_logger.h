#ifndef SD_CARD_LOGGER_H
#define SD_CARD_LOGGER_H
#include <Arduino.h>
#include <SD.h>
#include <Simpletimer.h>
#define SD_DEFAULT_CS_PIN 10
class sd_card_logger
{
public:
    sd_card_logger(String filename, uint8_t CSpin = SD_DEFAULT_CS_PIN)
    {
        this->CSpin = CSpin;
        _filename = filename;
        _timer = new Simpletimer;
    }
    ~sd_card_logger()
    {
        delete[] _timer;
    }
    void init(String bootmessage, uint8_t CSpin = SD_DEFAULT_CS_PIN);
    bool log(String logmessage, int logging_freq);

private:
    uint8_t CSpin;
    Simpletimer *_timer = nullptr;
    File *_file = nullptr;
    String _filename;
    unsigned long lastMillis = 0;
};

#endif