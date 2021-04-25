#include "CPU.h"
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

void test_0xa9_lda_immidiate_load_data()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x05, 0x00};

    cpu.load_and_run(program);

    assert(cpu.register_a == 0x05);
    assert(cpu.status == 0x00000000);
}

void test_0xa9_lda_zero_flag()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x00, 0x00};

    cpu.load_and_run(program);

    assert(cpu.register_a == 0b00);
    assert(cpu.status == 0b00000010);
}

void test_0xaa_tax_move_a_to_x()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x05, 0xaa, 0x00};

    cpu.load_and_run(program);

    assert(cpu.register_a == 0x05);
    assert(cpu.register_x == 0x05);
}

void test_inx_overflow()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0xff, 0xaa, 0xe8, 0xe8, 0x00};

    cpu.load_and_run(program);

    assert(cpu.register_x == 1);
}

void test_5_ops_working_together()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0xc0, 0xaa, 0xe8, 0x0};

    cpu.load_and_run(program);

    assert(cpu.register_x == 0xc1);
}

void test_lda_from_memory()
{
    mysn::CPU cpu = mysn::CPU();
    cpu.mem_write(0x10, 0x55);
    vector<uint8_t> program = {0xa5, 0x10, 0x00};

    cpu.load_and_run(program);

    assert(cpu.register_a == 0x55);
}

void test_adc()
{
    mysn::CPU cpu = mysn::CPU();

    /**
        ADC #255
        BRK
     */
    vector<uint8_t> program1 = {0x69, 0xff, 0x00};
    cpu.load_and_run(program1);
    assert(cpu.register_a == 0xff);
    assert(cpu.status == 0b10000000);

    /**
        ADC #255
        ADC #255
        BRK
     */
    vector<uint8_t> program2 = {0x69, 0xff, 0x69, 0xff, 0x00};
    cpu.load_and_run(program2);
    assert(cpu.register_a == 0xfe);
    assert(cpu.status == 0b10000001);

    /**
        ADC $00
        ADC #127
        BRK
     */
    vector<uint8_t> program3 = {0x65, 0x00, 0x69, 0x7f, 0x00};
    cpu.load_and_run(program3);
    assert(cpu.register_a == 0x7f);
    assert(cpu.status == 0b00000000);
}

void test_and()
{
    mysn::CPU cpu = mysn::CPU();

    /**
        LDA #$01
        AND #234
        BRK
     */
    vector<uint8_t> program1 = {0xa9, 0x01, 0x29, 0xea, 0x00};
    cpu.load_and_run(program1);
    assert(cpu.register_a == 0x00);
    assert(cpu.status == 0b00000010);

    /**
        LDA #$ff
        AND #255
        BRK
     */
    vector<uint8_t> program2 = {0xa9, 0xff, 0x29, 0xff, 0x00};
    cpu.load_and_run(program2);
    assert(cpu.register_a == 0xff);
    assert(cpu.status == 0b10000000);
}

void test_asl()
{
    mysn::CPU cpu = mysn::CPU();

    /**
        LDA #$ff
        AND #255
        ASL A
        BRK
     */
    vector<uint8_t> program1 = {0xa9, 0xff, 0x29, 0xff, 0x0a, 0x00};
    cpu.load_and_run(program1);
    assert(cpu.register_a == 0xfe);
    assert(cpu.status == 0b10000001);

    /**
        LDA #$aa
        STA $aa
        ASL $aa
        BRK
     */
    vector<uint8_t> program2 = {0xa9, 0xaa, 0x85, 0xaa, 0x06, 0xaa, 0x00};
    cpu.load_and_run(program2);
    assert(cpu.register_a == 0xaa);
    assert(cpu.status == 0b00000001);
    assert(cpu.mem_read(0xaa) == 0x54);
}

void test_set_clear_flag()
{
    mysn::CPU cpu = mysn::CPU();

    cpu.set_flag(mysn::CpuFlags::Carry);
    assert(cpu.status == 0b00000001);

    cpu.set_flag(mysn::CpuFlags::Overflow);
    assert(cpu.status == 0b01000001);

    cpu.clear_flag(mysn::CpuFlags::Carry);
    assert(cpu.status == 0b01000000);

    cpu.set_flag(mysn::CpuFlags::Negative);
    assert(cpu.status == 0b11000000);
}

void test_contain_flag()
{
    mysn::CPU cpu = mysn::CPU();

    cpu.set_flag(mysn::CpuFlags::Carry);
    assert(cpu.status == 0b00000001);
    assert(cpu.contain_flag(mysn::CpuFlags::Carry));

    cpu.set_flag(mysn::CpuFlags::Overflow);
    assert(cpu.status == 0b01000001);
    assert(cpu.contain_flag(mysn::CpuFlags::Overflow));
    assert(cpu.contain_flag(mysn::CpuFlags::Carry));
    assert(!cpu.contain_flag(mysn::CpuFlags::Zero));

    cpu.clear_flag(mysn::CpuFlags::Carry);
    assert(cpu.status == 0b01000000);
    assert(cpu.contain_flag(mysn::CpuFlags::Overflow));

    cpu.set_flag(mysn::CpuFlags::Negative);
    assert(cpu.status == 0b11000000);
    assert(cpu.contain_flag(mysn::CpuFlags::Negative));
}

int main()
{
    test_0xa9_lda_immidiate_load_data();
    test_0xa9_lda_zero_flag();
    test_0xaa_tax_move_a_to_x();
    test_inx_overflow();
    test_5_ops_working_together();
    test_lda_from_memory();

    test_adc();
    test_and();
    test_asl();
    test_set_clear_flag();
    test_contain_flag();
}