#include "SD_card_logger.h"

void sd_card_logger::init(String bootmessage, uint8_t pin_cs)
{
    if (pin_cs != SD_DEFAULT_CS_PIN)
        this->pin_cs = pin_cs;

    if (!SD.begin(this->pin_cs))
    {
        return;
    }

    txt_file = &SD.open(txt_filename, FILE_WRITE);

    if (!txt_file)
    {
        return;
    }
    txt_file->println();
    txt_file->println(bootmessage);
    txt_file->close();
}

bool sd_card_logger::log(String logmessage, int logging_freq)
{
    if (timer->timer(logging_freq))
    {
        txt_file = &SD.open(txt_filename, FILE_WRITE);
        if (!txt_file)
        {
            return false;
        }
        else
        {

            txt_file->print(logmessage);

            txt_file->close();
            return (true);
        }
    }
}
bool sd_card_logger::log(String logmessage)
{

    txt_file = &SD.open(txt_filename, FILE_WRITE);
    if (!txt_file)
    {
        return false;
    }
    else
    {

        txt_file->print(logmessage);
        txt_file->close();
        return (true);
    }
}