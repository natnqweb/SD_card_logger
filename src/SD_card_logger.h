#pragma once
#include <Arduino.h>
#include <SD.h>
#include <Simpletimer.h>
#define SD_DEFAULT_CS_PIN 10
class sd_card_logger
{
public:
    sd_card_logger(String filename, uint8_t pin_cs = SD_DEFAULT_CS_PIN)
    {
        this->pin_cs = pin_cs;
        txt_filename = filename;
        timer = new Simpletimer;
    }
    ~sd_card_logger()
    {
        delete timer;
    }
    void init(String bootmessage, uint8_t pin_cs = SD_DEFAULT_CS_PIN);
    bool log(String logmessage, int logging_freq);
    bool log(String logmessage);

private:
    uint8_t pin_cs{SD_DEFAULT_CS_PIN};
    Simpletimer *timer = nullptr;
    File *txt_file = nullptr;
    String txt_filename{};
    unsigned long lastMillis = 0;
};
