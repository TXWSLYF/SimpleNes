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

        {0x18, CPUOpcodes(0x18, CPUOpcodeMnemonics::CLC, 1, 2, AddressingMode::NoneAddressing)},
        {0xD8, CPUOpcodes(0xD8, CPUOpcodeMnemonics::CLD, 1, 2, AddressingMode::NoneAddressing)},
        {0x58, CPUOpcodes(0x58, CPUOpcodeMnemonics::CLI, 1, 2, AddressingMode::NoneAddressing)},
        {0xB8, CPUOpcodes(0xB8, CPUOpcodeMnemonics::CLV, 1, 2, AddressingMode::NoneAddressing)},

        {0xc9, CPUOpcodes(0xc9, CPUOpcodeMnemonics::CMP, 2, 2, AddressingMode::Immediate)},
        {0xc5, CPUOpcodes(0xc5, CPUOpcodeMnemonics::CMP, 2, 3, AddressingMode::ZeroPage)},
        {0xd5, CPUOpcodes(0xd5, CPUOpcodeMnemonics::CMP, 2, 4, AddressingMode::ZeroPage_X)},
        {0xcd, CPUOpcodes(0xcd, CPUOpcodeMnemonics::CMP, 3, 4, AddressingMode::Absolute)},
        {0xdd, CPUOpcodes(0xdd, CPUOpcodeMnemonics::CMP, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0xd9, CPUOpcodes(0xd9, CPUOpcodeMnemonics::CMP, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0xc1, CPUOpcodes(0xc1, CPUOpcodeMnemonics::CMP, 2, 6, AddressingMode::Indirect_X)},
        {0xd1, CPUOpcodes(0xd1, CPUOpcodeMnemonics::CMP, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0xe0, CPUOpcodes(0xe0, CPUOpcodeMnemonics::CPX, 2, 2, AddressingMode::Immediate)},
        {0xe4, CPUOpcodes(0xe4, CPUOpcodeMnemonics::CPX, 2, 3, AddressingMode::ZeroPage)},
        {0xec, CPUOpcodes(0xec, CPUOpcodeMnemonics::CPX, 3, 4, AddressingMode::Absolute)},

        {0xc0, CPUOpcodes(0xc0, CPUOpcodeMnemonics::CPY, 2, 2, AddressingMode::Immediate)},
        {0xc4, CPUOpcodes(0xc4, CPUOpcodeMnemonics::CPY, 2, 3, AddressingMode::ZeroPage)},
        {0xcc, CPUOpcodes(0xcc, CPUOpcodeMnemonics::CPY, 3, 4, AddressingMode::Absolute)},

        {0xc6, CPUOpcodes(0xc6, CPUOpcodeMnemonics::DEC, 2, 5, AddressingMode::ZeroPage)},
        {0xd6, CPUOpcodes(0xd6, CPUOpcodeMnemonics::DEC, 2, 6, AddressingMode::ZeroPage_X)},
        {0xce, CPUOpcodes(0xce, CPUOpcodeMnemonics::DEC, 3, 6, AddressingMode::Absolute)},
        {0xde, CPUOpcodes(0xde, CPUOpcodeMnemonics::DEC, 3, 7, AddressingMode::Absolute_X)},

        {0xca, CPUOpcodes(0xca, CPUOpcodeMnemonics::DEX, 1, 2, AddressingMode::NoneAddressing)},
        {0x88, CPUOpcodes(0x88, CPUOpcodeMnemonics::DEY, 1, 2, AddressingMode::NoneAddressing)},

        {0x49, CPUOpcodes(0x49, CPUOpcodeMnemonics::EOR, 2, 2, AddressingMode::Immediate)},
        {0x45, CPUOpcodes(0x45, CPUOpcodeMnemonics::EOR, 2, 3, AddressingMode::ZeroPage)},
        {0x55, CPUOpcodes(0x55, CPUOpcodeMnemonics::EOR, 2, 4, AddressingMode::ZeroPage_X)},
        {0x4d, CPUOpcodes(0x4d, CPUOpcodeMnemonics::EOR, 3, 4, AddressingMode::Absolute)},
        {0x5d, CPUOpcodes(0x5d, CPUOpcodeMnemonics::EOR, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0x59, CPUOpcodes(0x59, CPUOpcodeMnemonics::EOR, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0x41, CPUOpcodes(0x41, CPUOpcodeMnemonics::EOR, 2, 6, AddressingMode::Indirect_X)},
        {0x51, CPUOpcodes(0x51, CPUOpcodeMnemonics::EOR, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0xe6, CPUOpcodes(0xe6, CPUOpcodeMnemonics::INC, 2, 5, AddressingMode::ZeroPage)},
        {0xf6, CPUOpcodes(0xf6, CPUOpcodeMnemonics::INC, 2, 6, AddressingMode::ZeroPage_X)},
        {0xee, CPUOpcodes(0xee, CPUOpcodeMnemonics::INC, 3, 6, AddressingMode::Absolute)},
        {0xfe, CPUOpcodes(0xfe, CPUOpcodeMnemonics::INC, 3, 7, AddressingMode::Absolute_X)},

        {0xe8, CPUOpcodes(0xe8, CPUOpcodeMnemonics::INX, 1, 2, AddressingMode::NoneAddressing)},
        {0xc8, CPUOpcodes(0xc8, CPUOpcodeMnemonics::INY, 1, 2, AddressingMode::NoneAddressing)},

        {0x4c, CPUOpcodes(0x4c, CPUOpcodeMnemonics::JMP, 3, 3, AddressingMode::Absolute)},
        {0x6c, CPUOpcodes(0x6c, CPUOpcodeMnemonics::JMP, 3, 5, AddressingMode::Indirect)},

        {0x20, CPUOpcodes(0x20, CPUOpcodeMnemonics::JSR, 3, 6, AddressingMode::Absolute)},

        {0xa9, CPUOpcodes(0xa9, CPUOpcodeMnemonics::LDA, 2, 2, AddressingMode::Immediate)},
        {0xa5, CPUOpcodes(0xa5, CPUOpcodeMnemonics::LDA, 2, 3, AddressingMode::ZeroPage)},
        {0xb5, CPUOpcodes(0xb5, CPUOpcodeMnemonics::LDA, 2, 4, AddressingMode::ZeroPage_X)},
        {0xad, CPUOpcodes(0xad, CPUOpcodeMnemonics::LDA, 3, 4, AddressingMode::Absolute)},
        {0xbd, CPUOpcodes(0xbd, CPUOpcodeMnemonics::LDA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0xb9, CPUOpcodes(0xb9, CPUOpcodeMnemonics::LDA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0xa1, CPUOpcodes(0xa1, CPUOpcodeMnemonics::LDA, 2, 6, AddressingMode::Indirect_X)},
        {0xb1, CPUOpcodes(0xb1, CPUOpcodeMnemonics::LDA, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0xa2, CPUOpcodes(0xa2, CPUOpcodeMnemonics::LDX, 2, 2, AddressingMode::Immediate)},
        {0xa6, CPUOpcodes(0xa6, CPUOpcodeMnemonics::LDX, 2, 3, AddressingMode::ZeroPage)},
        {0xb6, CPUOpcodes(0xb6, CPUOpcodeMnemonics::LDX, 2, 4, AddressingMode::ZeroPage_Y)},
        {0xae, CPUOpcodes(0xae, CPUOpcodeMnemonics::LDX, 3, 4, AddressingMode::Absolute)},
        {0xbe, CPUOpcodes(0xbe, CPUOpcodeMnemonics::LDX, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},

        {0xa0, CPUOpcodes(0xa0, CPUOpcodeMnemonics::LDY, 2, 2, AddressingMode::Immediate)},
        {0xa4, CPUOpcodes(0xa4, CPUOpcodeMnemonics::LDY, 2, 3, AddressingMode::ZeroPage)},
        {0xb4, CPUOpcodes(0xb4, CPUOpcodeMnemonics::LDY, 2, 4, AddressingMode::ZeroPage_X)},
        {0xac, CPUOpcodes(0xac, CPUOpcodeMnemonics::LDY, 3, 4, AddressingMode::Absolute)},
        {0xbc, CPUOpcodes(0xbc, CPUOpcodeMnemonics::LDY, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},

        {0x4a, CPUOpcodes(0x4a, CPUOpcodeMnemonics::LSR, 1, 2, AddressingMode::Accumulator)},
        {0x46, CPUOpcodes(0x46, CPUOpcodeMnemonics::LSR, 2, 5, AddressingMode::ZeroPage)},
        {0x56, CPUOpcodes(0x56, CPUOpcodeMnemonics::LSR, 2, 6, AddressingMode::ZeroPage_X)},
        {0x4e, CPUOpcodes(0x4e, CPUOpcodeMnemonics::LSR, 3, 6, AddressingMode::Absolute)},
        {0x5e, CPUOpcodes(0x5e, CPUOpcodeMnemonics::LSR, 3, 7, AddressingMode::Absolute_X)},

        {0xea, CPUOpcodes(0xea, CPUOpcodeMnemonics::NOP, 1, 2, AddressingMode::NoneAddressing)},

        {0x09, CPUOpcodes(0x09, CPUOpcodeMnemonics::ORA, 2, 2, AddressingMode::Immediate)},
        {0x05, CPUOpcodes(0x05, CPUOpcodeMnemonics::ORA, 2, 3, AddressingMode::ZeroPage)},
        {0x15, CPUOpcodes(0x15, CPUOpcodeMnemonics::ORA, 2, 4, AddressingMode::ZeroPage_X)},
        {0x0d, CPUOpcodes(0x0d, CPUOpcodeMnemonics::ORA, 3, 4, AddressingMode::Absolute)},
        {0x1d, CPUOpcodes(0x1d, CPUOpcodeMnemonics::ORA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0x19, CPUOpcodes(0x19, CPUOpcodeMnemonics::ORA, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0x01, CPUOpcodes(0x01, CPUOpcodeMnemonics::ORA, 2, 6, AddressingMode::Indirect_X)},
        {0x11, CPUOpcodes(0x11, CPUOpcodeMnemonics::ORA, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0x48, CPUOpcodes(0x48, CPUOpcodeMnemonics::PHA, 1, 3, AddressingMode::NoneAddressing)},
        {0x08, CPUOpcodes(0x08, CPUOpcodeMnemonics::PHP, 1, 3, AddressingMode::NoneAddressing)},
        {0x68, CPUOpcodes(0x68, CPUOpcodeMnemonics::PLA, 1, 4, AddressingMode::NoneAddressing)},
        {0x28, CPUOpcodes(0x28, CPUOpcodeMnemonics::PLP, 1, 4, AddressingMode::NoneAddressing)},

        {0x2a, CPUOpcodes(0x2a, CPUOpcodeMnemonics::ROL, 1, 2, AddressingMode::Accumulator)},
        {0x26, CPUOpcodes(0x26, CPUOpcodeMnemonics::ROL, 2, 5, AddressingMode::ZeroPage)},
        {0x36, CPUOpcodes(0x36, CPUOpcodeMnemonics::ROL, 2, 6, AddressingMode::ZeroPage_X)},
        {0x2e, CPUOpcodes(0x2e, CPUOpcodeMnemonics::ROL, 3, 6, AddressingMode::Absolute)},
        {0x3e, CPUOpcodes(0x3e, CPUOpcodeMnemonics::ROL, 3, 7, AddressingMode::Absolute_X)},

        {0x6a, CPUOpcodes(0x6a, CPUOpcodeMnemonics::ROR, 1, 2, AddressingMode::Accumulator)},
        {0x66, CPUOpcodes(0x66, CPUOpcodeMnemonics::ROR, 2, 5, AddressingMode::ZeroPage)},
        {0x76, CPUOpcodes(0x76, CPUOpcodeMnemonics::ROR, 2, 6, AddressingMode::ZeroPage_X)},
        {0x6e, CPUOpcodes(0x6e, CPUOpcodeMnemonics::ROR, 3, 6, AddressingMode::Absolute)},
        {0x7e, CPUOpcodes(0x7e, CPUOpcodeMnemonics::ROR, 3, 7, AddressingMode::Absolute_X)},

        {0x40, CPUOpcodes(0x40, CPUOpcodeMnemonics::RTI, 1, 6, AddressingMode::NoneAddressing)},
        {0x60, CPUOpcodes(0x60, CPUOpcodeMnemonics::RTS, 1, 6, AddressingMode::NoneAddressing)},

        {0xe9, CPUOpcodes(0xe9, CPUOpcodeMnemonics::SBC, 2, 2, AddressingMode::Immediate)},
        {0xe5, CPUOpcodes(0xe5, CPUOpcodeMnemonics::SBC, 2, 3, AddressingMode::ZeroPage)},
        {0xf5, CPUOpcodes(0xf5, CPUOpcodeMnemonics::SBC, 2, 4, AddressingMode::ZeroPage_X)},
        {0xed, CPUOpcodes(0xed, CPUOpcodeMnemonics::SBC, 3, 4, AddressingMode::Absolute)},
        {0xfd, CPUOpcodes(0xfd, CPUOpcodeMnemonics::SBC, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_X)},
        {0xf9, CPUOpcodes(0xf9, CPUOpcodeMnemonics::SBC, 3, 4 /*+1 if page crossed*/, AddressingMode::Absolute_Y)},
        {0xe1, CPUOpcodes(0xe1, CPUOpcodeMnemonics::SBC, 2, 6, AddressingMode::Indirect_X)},
        {0xf1, CPUOpcodes(0xf1, CPUOpcodeMnemonics::SBC, 2, 5 /*+1 if page crossed*/, AddressingMode::Indirect_Y)},

        {0x38, CPUOpcodes(0x38, CPUOpcodeMnemonics::SEC, 1, 2, AddressingMode::NoneAddressing)},
        {0xf8, CPUOpcodes(0xf8, CPUOpcodeMnemonics::SED, 1, 2, AddressingMode::NoneAddressing)},
        {0x78, CPUOpcodes(0x78, CPUOpcodeMnemonics::SEI, 1, 2, AddressingMode::NoneAddressing)},

        {0x85, CPUOpcodes(0x85, CPUOpcodeMnemonics::STA, 2, 3, AddressingMode::ZeroPage)},
        {0x95, CPUOpcodes(0x95, CPUOpcodeMnemonics::STA, 2, 4, AddressingMode::ZeroPage_X)},
        {0x8d, CPUOpcodes(0x8d, CPUOpcodeMnemonics::STA, 3, 4, AddressingMode::Absolute)},
        {0x9d, CPUOpcodes(0x9d, CPUOpcodeMnemonics::STA, 3, 5, AddressingMode::Absolute_X)},
        {0x99, CPUOpcodes(0x99, CPUOpcodeMnemonics::STA, 3, 5, AddressingMode::Absolute_Y)},
        {0x81, CPUOpcodes(0x81, CPUOpcodeMnemonics::STA, 2, 6, AddressingMode::Indirect_X)},
        {0x91, CPUOpcodes(0x91, CPUOpcodeMnemonics::STA, 2, 6, AddressingMode::Indirect_Y)},

        {0x86, CPUOpcodes(0x86, CPUOpcodeMnemonics::STX, 2, 3, AddressingMode::ZeroPage)},
        {0x96, CPUOpcodes(0x96, CPUOpcodeMnemonics::STX, 2, 4, AddressingMode::ZeroPage_Y)},
        {0x8e, CPUOpcodes(0x8e, CPUOpcodeMnemonics::STX, 3, 4, AddressingMode::Absolute)},

        {0x84, CPUOpcodes(0x84, CPUOpcodeMnemonics::STY, 2, 3, AddressingMode::ZeroPage)},
        {0x94, CPUOpcodes(0x94, CPUOpcodeMnemonics::STY, 2, 4, AddressingMode::ZeroPage_X)},
        {0x8c, CPUOpcodes(0x8c, CPUOpcodeMnemonics::STY, 3, 4, AddressingMode::Absolute)},

        {0xaa, CPUOpcodes(0xaa, CPUOpcodeMnemonics::TAX, 1, 2, AddressingMode::NoneAddressing)},
    };
}
