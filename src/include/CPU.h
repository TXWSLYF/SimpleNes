#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>

namespace mysn
{
    using Byte = std::uint8_t;
    using Address = std::uint16_t;

    class CPU
    {
    private:
        Address program_counter;
        Byte register_a;
        Byte register_x;

        // Status flags
        Byte status;

        std::vector<Byte> memory;

        void update_zero_and_negative_flags(Byte result);
        void lda(Byte value);
        void tax();
        void inx();

        Byte mem_read(Address addr);
        void mem_write(Address addr, Byte data);
        void load(std::vector<Byte> &program);
        void run();

    public:
        CPU();

        Byte get_register_a();
        Byte get_register_x();

        Byte get_status();

        void load_and_run(std::vector<Byte> &program);
    };
}

#endif // CPU_H
