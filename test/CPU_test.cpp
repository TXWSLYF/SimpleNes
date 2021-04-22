#include "CPU.h"
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

void test_0xa9_lda_immidiate_load_data()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x05, 0x00};

    cpu.interpret(program);

    assert(cpu.get_register_a() == 0x05);
    assert(cpu.get_status() == 0x00000000);
}

void test_0xa9_lda_zero_flag()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x00, 0x00};

    cpu.interpret(program);

    assert(cpu.get_register_a() == 0b00);
    assert(cpu.get_status() == 0b00000010);
}

void test_0xaa_tax_move_a_to_x()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0x05, 0xaa, 0x00};

    cpu.interpret(program);

    assert(cpu.get_register_a() == 0x05);
    assert(cpu.get_register_x() == 0x05);
}

void test_inx_overflow()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0xff, 0xaa, 0xe8, 0xe8, 0x00};

    cpu.interpret(program);

    assert(cpu.get_register_x() == 1);
}

void test_5_ops_working_together()
{
    mysn::CPU cpu = mysn::CPU();
    vector<uint8_t> program = {0xa9, 0xc0, 0xaa, 0xe8, 0x0};

    cpu.interpret(program);

    assert(cpu.get_register_x() == 0xc1);
}

int main()
{
    test_0xa9_lda_immidiate_load_data();
    test_0xa9_lda_zero_flag();
    test_0xaa_tax_move_a_to_x();
    test_inx_overflow();
    test_5_ops_working_together();
}