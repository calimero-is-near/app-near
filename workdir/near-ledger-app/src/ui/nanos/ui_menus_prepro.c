#include "ui_menus_prepro.h"

#include "../ui.h"

// TODO: These look repetitive and likely not matching what we want in terms of UX. Figure out how to refactor

const bagl_element_t * ui_address_prepro(const bagl_element_t *element) {
    if (element->component.userid > 0) {
        unsigned int display = (ux_step == element->component.userid - 1);
        if (display) {
            switch (element->component.userid) {
            case 1:
                UX_CALLBACK_SET_INTERVAL(2000);
                break;
            case 2:
                UX_CALLBACK_SET_INTERVAL(MAX(
                    3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
                break;
            }
        }
        if (!display)
             return NULL;
    }
    return element;
}

// display or not according to step, and adjust delay
const bagl_element_t * ui_verify_transfer_prepro(const bagl_element_t *element) {
    if (element->component.userid > 0) {
        unsigned int display = (ux_step == element->component.userid - 1);
        if (display) {
            switch (element->component.userid) {
            case 1:
                UX_CALLBACK_SET_INTERVAL(2000);
                break;
            case 2:
            case 3:
                UX_CALLBACK_SET_INTERVAL(MAX(
                    3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
                break;
            }
        }
        if (!display)
             return NULL;
    }
    return element;
}

const bagl_element_t * ui_verify_function_call_prepro(const bagl_element_t *element) {
    if (element->component.userid > 0) {
        unsigned int display = (ux_step == element->component.userid - 1);
        if (display) {
            UX_CALLBACK_SET_INTERVAL(
                MAX(2000, bagl_label_roundtrip_duration_ms(element, 7)));
        }
        if (!display) {
             return NULL;
        }
    }
    return element;
}

const bagl_element_t * ui_verify_transaction_prepro(const bagl_element_t *element) {
    if (element->component.userid > 0) {
        unsigned int display = (ux_step == element->component.userid - 1);
        if (display) {
            switch (element->component.userid) {
            case 1:
                UX_CALLBACK_SET_INTERVAL(2000);
                break;
            case 2:
            case 3:
                UX_CALLBACK_SET_INTERVAL(MAX(
                    3000, 1000 + bagl_label_roundtrip_duration_ms(element, 7)));
                break;
            }
        }
        if (!display)
             return NULL;
    }
    return element;
}