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

        {0x00, CPUOpcodes(0x00, CPUOpcodeMnemonics::BRK, 1, 7, AddressingMode::NoneAddressing)},
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
