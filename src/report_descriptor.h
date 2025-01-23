#include <inttypes.h>

uint8_t vrGloveReportDescriptor[] = 
{
    0x05, 0x01,    // UsagePage(Generic Desktop[0x0001])
    0x09, 0x04,    // UsageId(Joystick[0x0004])
    0xA1, 0x01,    // Collection(Application)
    0x85, 0x01,    //     ReportId(1)
    0x09, 0x39,    //     UsageId(Hat Switch[0x0039])
    0x15, 0x00,    //     LogicalMinimum(0)
    0x25, 0x03,    //     LogicalMaximum(3)
    0x95, 0x01,    //     ReportCount(1)
    0x75, 0x02,    //     ReportSize(2)
    0x81, 0x02,    //     Input(Data, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0x75, 0x06,    //     ReportSize(6)
    0x81, 0x03,    //     Input(Constant, Variable, Absolute, NoWrap, Linear, PreferredState, NoNullPosition, BitField)
    0xC0,          // EndCollection()
};