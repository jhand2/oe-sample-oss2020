#include <openenclave/host.h>
#include "sample_u.h"

int main(int argc, const char **argv)
{
    int flags = OE_ENCLAVE_FLAG_DEBUG | OE_ENCLAVE_FLAG_SIMULATE;
    oe_enclave_t *enclave = NULL;
    oe_result_t result;
    int ret = -1;

    result = oe_create_sample_enclave(
            argv[1], OE_ENCLAVE_TYPE_SGX, flags, NULL, 0, &enclave);
    if (result != OE_OK)
        goto out;

    int a = 1;
    int b = 2;
    int val;
    result = compute_result_ecall(enclave, &val, a, b);
    if (result != OE_OK)
        goto out;

    printf("Computed Value: %d\n", val);

    ret = 0;
out:
    if (enclave)
        oe_terminate_enclave(enclave);

    return ret;
}
