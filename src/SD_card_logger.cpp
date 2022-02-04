#include "SD_card_logger.h"

void sd_card_logger::init(String bootmessage, uint8_t CSpin)
{
    if (CSpin != SD_DEFAULT_CS_PIN)
        this->CSpin = CSpin;

    // init the SD card
    if (!SD.begin(this->CSpin))
    {

        // don't do anything more:
    }
    _file = &SD.open(_filename, FILE_WRITE);
    if (!_file)
    {
    }
    _file->println();
    _file->println(bootmessage);
    _file->close();
}

bool sd_card_logger::log(String logmessage, int logging_freq)
{
    if (_timer->timer(logging_freq))
    {

        // check if it's been over 10 ms since the last line added
        _file = &SD.open(_filename, FILE_WRITE);
        if (!_file)
        {
            return false;
        }
        else
        {

            _file->print(logmessage);

            _file->close();
            return (true);
        }
    }
}