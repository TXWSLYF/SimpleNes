#include "CPU.h"

namespace mysn
{
    CPU::CPU() : program_counter(0),
                 register_a(0),
                 register_x(0),
                 status(0),
                 memory(0xFFFF, 0){};

    void CPU::run()
    {
        while (true)
        {
            auto opscode = mem_read(program_counter);
            ++program_counter;

            switch (opscode)
            {
            case 0xA9:
            {
                auto param = mem_read(program_counter);
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

    void CPU::lda(Byte value)
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

    void CPU::update_zero_and_negative_flags(Byte result)
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

    Byte CPU::get_register_a()
    {
        return register_a;
    };

    Byte CPU::get_register_x()
    {
        return register_x;
    };

    Byte CPU::get_status()
    {
        return status;
    };

    Byte CPU::mem_read(Address addr)
    {
        return memory[addr];
    }

    void CPU::mem_write(Address addr, Byte data)
    {
        memory[addr] = data;
    }

    void CPU::load(std::vector<Byte> &program)
    {
        Address start = 0x8000;
        program_counter = start;

        // 程序数据（Program ROM/PRG ROM），存储在插入的墨盒中（Cartridges），存储的是游戏的代码
        // 从内存地址的 0x8000 开始装载
        // TODO: 暂时不考虑溢出情况
        for (auto i : program)
        {
            memory[start] = i;
            ++start;
        }
    }

    void CPU::load_and_run(std::vector<Byte> &program)
    {
        load(program);
        run();
    }

}