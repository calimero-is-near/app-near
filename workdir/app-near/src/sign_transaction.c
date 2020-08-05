#include "sign_transaction.h"
#include "os.h"
#include "ux.h"
#include "utils.h"
#include "main.h"

//////////////////////////////////////////////////////////////////////

#define INFO_STEP(name, info_title, info_text) \
UX_STEP_NOCB( \
    name, \
    bnnn_paging, \
    { \
        .title = info_title, \
        .text = info_text, \
    })

INFO_STEP(sign_flow_intro_step, "Confirm",  ui_context.line1);
INFO_STEP(sign_flow_receiver_step, "To",  ui_context.line2);
INFO_STEP(sign_flow_signer_step, "From",  ui_context.line3);
INFO_STEP(sign_flow_amount_step, "Amount",  ui_context.amount);
INFO_STEP(sign_flow_deposit_step, "Deposit",  ui_context.line5);
INFO_STEP(sign_flow_args_step, "Args",  ui_context.line4);
INFO_STEP(sign_flow_to_account_step, "To Account",  ui_context.line3);
INFO_STEP(sign_flow_contract_step, "Contract",  ui_context.line2);
INFO_STEP(sign_flow_allowance_step, "Allowance",  ui_context.line5);
INFO_STEP(sign_flow_danger_step, "DANGER", "This gives full access to a device other than Ledger");

UX_STEP_VALID(
    sign_flow_approve_step,
    pb,
    send_response(set_result_sign(), true),
    {
        &C_icon_validate_14,
        "Approve",
    });

UX_STEP_VALID(
    sign_flow_reject_step,
    pb,
    send_response(0, false),
    {
        &C_icon_crossmark,
        "Reject",
    });

UX_FLOW(
    ux_display_sign_flow,
    &sign_flow_intro_step,
    &sign_flow_receiver_step,
    &sign_flow_signer_step,
    &sign_flow_approve_step,
    &sign_flow_reject_step);

UX_FLOW(
    ux_display_sign_transfer_flow,
    &sign_flow_intro_step,
    &sign_flow_amount_step,
    &sign_flow_receiver_step,
    &sign_flow_signer_step,
    &sign_flow_approve_step,
    &sign_flow_reject_step);

UX_FLOW(
    ux_display_sign_function_call_flow,
    &sign_flow_intro_step,
    &sign_flow_deposit_step,
    &sign_flow_receiver_step,
    &sign_flow_signer_step,
    &sign_flow_args_step,
    &sign_flow_approve_step,
    &sign_flow_reject_step);

UX_FLOW(
    ux_display_sign_add_function_call_key_flow,
    &sign_flow_intro_step,
    &sign_flow_to_account_step,
    &sign_flow_contract_step,
    &sign_flow_allowance_step,
    &sign_flow_approve_step,
    &sign_flow_reject_step);

UX_FLOW(
    ux_display_sign_add_full_access_key_flow,
    &sign_flow_intro_step,
    &sign_flow_danger_step,
    &sign_flow_contract_step,
    &sign_flow_approve_step,
    &sign_flow_reject_step);

void print_ui_context() {
    for (int i = 0; i < 6; i++) {
        PRINTF("line %d: %s\n", i, &ui_context.line1[sizeof(ui_context.line1) * i]);
    }
}

void sign_ux_flow_init() {
    PRINTF("sign_ux_flow_init\n");
    print_ui_context();
    ux_flow_init(0, ux_display_sign_flow, NULL);
}

void sign_transfer_ux_flow_init() {
    PRINTF("sign_transfer_ux_flow_init\n");
    print_ui_context();
    ux_flow_init(0, ux_display_sign_transfer_flow, NULL);
}

void sign_function_call_ux_flow_init() {
    PRINTF("sign_function_call_ux_flow_init\n");
    print_ui_context();
    ux_flow_init(0, ux_display_sign_function_call_flow, NULL);
}

void sign_add_function_call_key_ux_flow_init() {
    PRINTF("sign_add_function_call_key_ux_flow_init\n");
    print_ui_context();
    ux_flow_init(0, ux_display_sign_add_function_call_key_flow, NULL);
}

void sign_add_full_access_key_ux_flow_init() {
    PRINTF("sign_add_full_access_key_ux_flow_init\n");
    print_ui_context();
    ux_flow_init(0, ux_display_sign_add_full_access_key_flow, NULL);
}

void handle_sign_transaction(uint8_t p1, uint8_t p2, uint8_t *input_buffer, uint16_t input_length, volatile unsigned int *flags, volatile unsigned int *tx) {
    UNUSED(input_length);
    UNUSED(p2);

    // TODO: Should clear context on first chunk?
    // init_context();

    // TODO: Move handling command here from main.c
    sign_ux_flow_init();
    *flags |= IO_ASYNCH_REPLY;
}
