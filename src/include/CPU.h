#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>

namespace mysn
{
    class CPU
    {
    private:
        std::uint16_t program_counter;
        std::uint8_t register_a;
        std::uint8_t register_x;

        // Status flags
        std::uint8_t status;

        void update_zero_and_negative_flags(std::uint8_t result);
        void lda(std::uint8_t value);
        void tax();
        void inx();

    public:
        CPU();

        void interpret(std::vector<std::uint8_t> &program);

        std::uint8_t get_register_a();
        std::uint8_t get_register_x();

        std::uint8_t get_status();
    };
}

#endif // CPU_H
