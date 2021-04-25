#include "CPUOpcodes.h"
#include <string>
#include <map>

namespace mysn
{
    CPUOpcodes::CPUOpcodes(Byte code,
                           CPUOpcodeMnemonics mnemonic,
                           Byte len,
                           Byte cycles,
                           AddressingMode mode)
    {
        this->code = code;
        this->mnemonic = mnemonic;
        this->len = len;
        this->cycles = cycles;
        this->mode = mode;
    }

    std::map<Byte, CPUOpcodes> CPUOpcodes::CPU_OPS_CODES_MAP = {
        {0x69, CPUOpcodes(0x69, CPUOpcodeMnemonics::ADC, 2, 2, AddressingMode::Immediate)},
        {0x65, CPUOpcodes(0x65, CPUOpcodeMnemonics::ADC, 2, 3, AddressingMode::ZeroPage)},
        {0x75, CPUOpcodes(0x75, CPUOpcodeMnemonics::ADC, 2, 4, AddressingMode::ZeroPage_X)},
        {0x6d, CPUOpcodes(0x6d, CPUOpcodeMnemonics::ADC, 3, 4, AddressingMode::Absolute)},
        {0x7d, CPUOpcodes(0x7d, CPUOpcodeMnemonics::ADC, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0x79, CPUOpcodes(0x79, CPUOpcodeMnemonics::ADC, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0x61, CPUOpcodes(0x61, CPUOpcodeMnemonics::ADC, 2, 6, AddressingMode::Indirect_X)},
        {0x71, CPUOpcodes(0x71, CPUOpcodeMnemonics::ADC, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0x29, CPUOpcodes(0x29, CPUOpcodeMnemonics::AND, 2, 2, AddressingMode::Immediate)},
        {0x25, CPUOpcodes(0x25, CPUOpcodeMnemonics::AND, 2, 3, AddressingMode::ZeroPage)},
        {0x35, CPUOpcodes(0x35, CPUOpcodeMnemonics::AND, 2, 4, AddressingMode::ZeroPage_X)},
        {0x2d, CPUOpcodes(0x2d, CPUOpcodeMnemonics::AND, 3, 4, AddressingMode::Absolute)},
        {0x3d, CPUOpcodes(0x3d, CPUOpcodeMnemonics::AND, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0x39, CPUOpcodes(0x39, CPUOpcodeMnemonics::AND, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0x21, CPUOpcodes(0x21, CPUOpcodeMnemonics::AND, 2, 6, AddressingMode::Indirect_X)},
        {0x31, CPUOpcodes(0x31, CPUOpcodeMnemonics::AND, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0x0A, CPUOpcodes(0x0A, CPUOpcodeMnemonics::ASL, 1, 2, AddressingMode::Accumulator)},
        {0x06, CPUOpcodes(0x06, CPUOpcodeMnemonics::ASL, 2, 5, AddressingMode::ZeroPage)},
        {0x16, CPUOpcodes(0x16, CPUOpcodeMnemonics::ASL, 2, 6, AddressingMode::ZeroPage_X)},
        {0x0E, CPUOpcodes(0x0E, CPUOpcodeMnemonics::ASL, 3, 6, AddressingMode::Absolute)},
        {0x1E, CPUOpcodes(0x1E, CPUOpcodeMnemonics::ASL, 3, 7, AddressingMode::Absolute_X)},

        {0x90, CPUOpcodes(0x90, CPUOpcodeMnemonics::BCC, 2, 2, AddressingMode::Relative)},
        {0xB0, CPUOpcodes(0xB0, CPUOpcodeMnemonics::BCS, 2, 2, AddressingMode::Relative)},
        {0xF0, CPUOpcodes(0xF0, CPUOpcodeMnemonics::BEQ, 2, 2, AddressingMode::Relative)},

        {0x24, CPUOpcodes(0x24, CPUOpcodeMnemonics::BIT, 2, 3, AddressingMode::ZeroPage)},
        {0x2c, CPUOpcodes(0x2c, CPUOpcodeMnemonics::BIT, 3, 4, AddressingMode::Absolute)},
        {0x30, CPUOpcodes(0x30, CPUOpcodeMnemonics::BMI, 2, 2, AddressingMode::Relative)},
        {0xD0, CPUOpcodes(0xD0, CPUOpcodeMnemonics::BNE, 2, 2, AddressingMode::Relative)},
        {0x10, CPUOpcodes(0x10, CPUOpcodeMnemonics::BPL, 2, 2, AddressingMode::Relative)},

        {0x00, CPUOpcodes(0x00, CPUOpcodeMnemonics::BRK, 1, 7, AddressingMode::NoneAddressing)},

        {0x50, CPUOpcodes(0x50, CPUOpcodeMnemonics::BVC, 2, 2, AddressingMode::Relative)},
        {0x70, CPUOpcodes(0x70, CPUOpcodeMnemonics::BVS, 2, 2, AddressingMode::Relative)},

        {0xaa, CPUOpcodes(0xaa, CPUOpcodeMnemonics::TAX, 1, 2, AddressingMode::NoneAddressing)},
        {0xe8, CPUOpcodes(0xe8, CPUOpcodeMnemonics::INX, 1, 2, AddressingMode::NoneAddressing)},

        {0xa9, CPUOpcodes(0xa9, CPUOpcodeMnemonics::LDA, 2, 2, AddressingMode::Immediate)},
        {0xa5, CPUOpcodes(0xa5, CPUOpcodeMnemonics::LDA, 2, 3, AddressingMode::ZeroPage)},
        {0xb5, CPUOpcodes(0xb5, CPUOpcodeMnemonics::LDA, 2, 4, AddressingMode::ZeroPage_X)},
        {0xad, CPUOpcodes(0xad, CPUOpcodeMnemonics::LDA, 3, 4, AddressingMode::Absolute)},
        {0xbd, CPUOpcodes(0xbd, CPUOpcodeMnemonics::LDA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0xb9, CPUOpcodes(0xb9, CPUOpcodeMnemonics::LDA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0xa1, CPUOpcodes(0xa1, CPUOpcodeMnemonics::LDA, 2, 6, AddressingMode::Indirect_X)},
        {0xb1, CPUOpcodes(0xb1, CPUOpcodeMnemonics::LDA, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0x85, CPUOpcodes(0x85, CPUOpcodeMnemonics::STA, 2, 3, AddressingMode::ZeroPage)},
        {0x95, CPUOpcodes(0x95, CPUOpcodeMnemonics::STA, 2, 4, AddressingMode::ZeroPage_X)},
        {0x8d, CPUOpcodes(0x8d, CPUOpcodeMnemonics::STA, 3, 4, AddressingMode::Absolute)},
        {0x9d, CPUOpcodes(0x9d, CPUOpcodeMnemonics::STA, 3, 5, AddressingMode::Absolute_X)},
        {0x99, CPUOpcodes(0x99, CPUOpcodeMnemonics::STA, 3, 5, AddressingMode::Absolute_Y)},
        {0x81, CPUOpcodes(0x81, CPUOpcodeMnemonics::STA, 2, 6, AddressingMode::Indirect_X)},
        {0x91, CPUOpcodes(0x91, CPUOpcodeMnemonics::STA, 2, 6, AddressingMode::Indirect_Y)}};
}
