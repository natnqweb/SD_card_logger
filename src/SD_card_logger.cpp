#include "SD_card_logger.h"

void sd_card_logger::init(String bootmessage)
{
    _bootmessage = bootmessage;
    pinMode(13, OUTPUT);

    // init the SD card
    if (!SD.begin())
    {

        // don't do anything more:
    }
    sd_card_logger::_file = &SD.open(_filename, FILE_WRITE);
    if (!this->_file)
    {
    }
    _file->println();
    _file->println(_bootmessage);
    _file->close();
}
bool sd_card_logger::log(String logmessage, int logging_freq)
{
    this->logmessage = logmessage;
    this->logging_freq = logging_freq;
    if (_timer->timer(logging_freq))
    {

        // check if it's been over 10 ms since the last line added
        sd_card_logger::_file = &SD.open(_filename, FILE_WRITE);
        if (!sd_card_logger::_file)
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