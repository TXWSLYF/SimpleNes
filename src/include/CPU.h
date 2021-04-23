#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>

namespace mysn
{
    using Byte = std::uint8_t;
    using Address = std::uint16_t;
    using DobuleByte = std::uint16_t;

    // 寻址模式，指示 CPU 该如何处理操作码的后 1~2 个字节（Byte）
    enum AddressingMode
    {
        Immediate,
        ZeroPage,
        ZeroPage_X,
        ZeroPage_Y,
        Absolute,
        Absolute_X,
        Absolute_Y,
        Indirect_X,
        Indirect_Y,
        NoneAddressing,
    };

    class CPU
    {
    private:
        Address program_counter;
        Byte register_a;
        Byte register_x;
        Byte register_y;

        // Status flags
        Byte status;

        std::vector<Byte> memory;

        void update_zero_and_negative_flags(Byte result);
        void lda(AddressingMode mode);
        void sta(AddressingMode mode);
        void tax();
        void inx();

        Byte mem_read(Address addr);
        DobuleByte mem_read_u16(Address addr);
        void mem_write_u16(Address addr, DobuleByte data);
        void load(std::vector<Byte> &program);
        void run();
        void reset();

        // 获取操作数地址
        Address get_operand_address(AddressingMode mode);

    public:
        CPU();

        Byte get_register_a();
        Byte get_register_x();

        Byte get_status();

        void load_and_run(std::vector<Byte> &program);
        void mem_write(Address addr, Byte data);
    };
}

#endif // CPU_H
