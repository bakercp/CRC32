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
  // Begin serial output for testing / debugging.
  Serial.begin(115200);
}

void loop()
{
  // The known CRC32 Checksum for the "Hello World" string below.
  const uint32_t KNOWN_CHECKSUM = 0x4A17B156;

  // Create some test data. This is an array of arbitrary bytes.
  // For this test, we'll create an array of bytes representing text.
  uint8_t byteBuffer[] = "Hello World";
  size_t numBytes = sizeof(byteBuffer) - 1;

  // Create a CRC32 checksum calculator.
  CRC32 crc;

  // Here we add each byte to the checksum, caclulating the checksum as we go.
  for (size_t i = 0; i < numBytes; i++)
  {
    crc.update(byteBuffer[i]);
  }

  // Alternatively, we can add an array of bytes in bulk.
  // crc.update(byteBuffer, numBytes);

  // Once we have added all of the data, generate the final CRC32 checksum.
  uint32_t checksum = crc.finalize();

  if (checksum == KNOWN_CHECKSUM)
  {
    Serial.println(F("TEST PASSED"));
  }
  else
  {
    Serial.println(F("TEST FAILED"));
  }

  // Wait a little bit because this is just a test.
  delay(3000);

}
