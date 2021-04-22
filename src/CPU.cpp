#include "CPU.h"

namespace mysn
{
    CPU::CPU() : program_counter(0), register_a(0), register_x(0), status(0){};

    void CPU::interpret(std::vector<std::uint8_t> &program)
    {
        program_counter = 0;

        while (true)
        {
            auto opscode = program[program_counter];
            ++program_counter;

            switch (opscode)
            {
            case 0xA9:
            {
                auto param = program[program_counter];
                ++program_counter;

                lda(param);

                break;
            }

            case 0xAA:
            {
                tax();

                break;
            }

            case 0xE8:
            {
                inx();

                break;
            }

            case 0x00:
            {
                return;
            }
            }
        }
    }

    void CPU::lda(std::uint8_t value)
    {
        register_a = value;
        update_zero_and_negative_flags(register_a);
    }

    void CPU::tax()
    {
        register_x = register_a;
        update_zero_and_negative_flags(register_x);
    }

    void CPU::inx()
    {
        ++register_x;
        update_zero_and_negative_flags(register_x);
    }

    void CPU::update_zero_and_negative_flags(std::uint8_t result)
    {
        if (result == 0)
        {
            status = status | 0b00000010;
        }
        else
        {
            status = status & 0b11111101;
        }

        if ((result & 0b10000000) != 0)
        {
            status = status | 0b10000000;
        }
        else
        {
            status = status & 0b01111111;
        }
    };

    std::uint8_t CPU::get_register_a()
    {
        return register_a;
    };

    std::uint8_t CPU::get_register_x()
    {
        return register_x;
    };

    std::uint8_t CPU::get_status()
    {
        return status;
    };

}