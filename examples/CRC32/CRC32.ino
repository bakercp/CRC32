// =============================================================================
//
// Copyright (c) 2013-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#include <CRC32.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  uint8_t buff[] = "Hello World";
  int len = sizeof(buff)-1;
  uint32_t checksum;
  
  checksum = CRC32::calculate(buff, len);
  Serial.print(F("Calculated1: 0x")); Serial.println(checksum, HEX);

  CRC32 crc;
  for (int i = 0; i < len; i++) {
    crc.update(buff[i]);
  }
  checksum = crc.finalize();
  Serial.print(F("Calculated2: 0x")); Serial.println(checksum, HEX);

  Serial.print(F("      Known: 0x4A17B156"));
  Serial.println();
  Serial.println();

  delay(3000);
}

