#ifndef CPUOPCODES_H
#define CPUOPCODES_H

#include "CPU.h"
#include <vector>
#include <string>
#include <map>

namespace mysn
{
    enum CPUOpcodeMnemonics
    {
        ADC,
        AND,
        ASL,

        BCC,
        BCS,
        BEQ,

        BIT,
        BMI,
        BNE,
        BPL,

        BRK,

        BVC,
        BVS,

        CLC,
        CLD,
        CLI,
        CLV,

        CMP,
        CPX,
        CPY,

        DEC,
        DEX,
        DEY,

        EOR,

        INC,

        INX,
        INY,
        JMP,
        JSR,

        LDA,
        LDX,
        LDY,

        LSR,
        NOP,
        ORA,

        PHA,
        PHP,
        PLA,
        PLP,

        ROL,
        ROR,

        RTI,
        RTS,

        SBC,

        SEC,
        SED,
        SEI,

        TAX,
        STA,
    };

    class CPUOpcodes
    {
    public:
        Byte code;
        CPUOpcodeMnemonics mnemonic;
        Byte len;
        Byte cycles;
        AddressingMode mode;

        CPUOpcodes(Byte code,
                   CPUOpcodeMnemonics mnemonic,
                   Byte len,
                   Byte cycles,
                   AddressingMode mode);

        static std::map<Byte, CPUOpcodes> CPU_OPS_CODES_MAP;
    };

}

#endif // CPUOPCODES_H
