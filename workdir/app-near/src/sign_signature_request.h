#include "os.h"
#include "cx.h"
#include "globals.h"

#ifndef _SIGN_SIGNATURE_REQUEST_H_
#define _SIGN_SIGNATURE_REQUEST_H_

void handle_signature_request(uint8_t p1, uint8_t p2, const uint8_t *input_buffer, uint16_t input_length, volatile unsigned int *flags, volatile unsigned int *tx);

#endif
