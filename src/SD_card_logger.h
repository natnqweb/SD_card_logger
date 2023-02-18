#ifndef SD_CARD_LOGGER_H
#define SD_CARD_LOGGER_H
#include <Arduino.h>
#include <SD.h>
#include <Simpletimer.h>
#define SD_DEFAULT_CS_PIN 10
class sd_card_logger
{
public:
    sd_card_logger(String A_filename, uint8_t A_CSpin);
    sd_card_logger(String A_filename);
    ~sd_card_logger();

    void init(String A_bootmessage);
    void init(String A_bootmessage, uint8_t A_CSpin);
    bool log(String A_logmessage, int A_logging_freq);

private:
    uint8_t m_CSpin{ SD_DEFAULT_CS_PIN };
    Simpletimer* m_timer = nullptr;
    String m_filename{};
};

#endif