#include "gdt.h"
#include "types.h"

GloabDescriptorTable::GloabDescriptorTable()
: nullSegmentSelector(0, 0, 0),
unusedSegmentSelector(0, 0, 0),
codeSegmentSelector(0, 64*1024*1024, 0x9A),
dataSegmentSelector(0, 64*1024*1024, 0x9A)
{
    uint32_t i[2];
    // #pragma warning(disable:0000) 
    i[0] = (uint32_t)this;
    i[1] = sizeof(GloabDescriptorTable) << 16;

    asm volatile("lgdt (%0)": :"p"(((uint8_t *)i)+ 2));
}

GloabDescriptorTable::~GloabDescriptorTable()
{
}

uint16_t GloabDescriptorTable::DataSegmentSelector()
{

}