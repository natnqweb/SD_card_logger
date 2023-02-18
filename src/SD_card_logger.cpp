#include "SD_card_logger.h"
sd_card_logger::sd_card_logger(String A_filename, uint8_t A_CSpin)
{
    m_CSpin = A_CSpin;
    m_filename = A_filename;
    m_timer = new Simpletimer{};
}

sd_card_logger::sd_card_logger(String A_filename)
{
    m_filename = A_filename;
    m_timer = new Simpletimer{};
}

sd_card_logger::~sd_card_logger()
{
    delete m_timer;
}

void sd_card_logger::init(String bootmessage, uint8_t CSpin)
{
    m_CSpin = CSpin;

    init(bootmessage);
}

void sd_card_logger::init(String bootmessage)
{
    if (!SD.begin(m_CSpin) || bootmessage.length() == 0)
    {
        return;
    }

    File file = SD.open(m_filename, FILE_WRITE);
    if (!file)
    {
        return;
    }
    file.println();
    file.println(bootmessage);
    file.close();
}

bool sd_card_logger::log(String logmessage, int logging_freq)
{
    if (m_timer->timer(logging_freq))
    {
        File file = SD.open(m_filename, FILE_WRITE);
        if (!file)
        {
            return false;
        }
        file.print(logmessage);
        file.close();
        return true;
    }
    return false;
}