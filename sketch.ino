#include "mbedtls/md.h"

void setup()
{

    Serial.begin(115200);

    char *payload = "Hello SHA 256"; // Changing this will lead to hash change
    byte shaResult[32];

    mbedtls_md_context_t ctx;
    mbedtls_md_type_t md_type = MBEDTLS_MD_SHA256;

    const size_t payloadLength = strlen(payload);

    mbedtls_md_init(&ctx);
    mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(md_type), 0);
    mbedtls_md_starts(&ctx);
    mbedtls_md_update(&ctx, (const unsigned char *)payload, payloadLength);
    mbedtls_md_finish(&ctx, shaResult);
    mbedtls_md_free(&ctx);

    Serial.print("Hash: ");

    for (int i = 0; i < sizeof(shaResult); i++)
    {
        char str[3];

        sprintf(str, "%02x", (int)shaResult[i]);
        Serial.print(str);
    }
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(10); // this speeds up the simulation
    // Expected Output:
    // Hash: 1b074f984ddfdf64b807fdc02a4c36089799daec07e9c429e32360cc18583343
}
