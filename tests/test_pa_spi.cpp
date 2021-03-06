#include <gtest/gtest.h>

#include "cap.h"
#include "pa_spi.h"
#include "saleae.h"


TEST(PaSpiTest, DISABLED_Functional) {
#if 0
    pa_spi_ctx_t *spi_ctx;

    uint64_t sample_count = 0;
    uint64_t decode_count = 0;
    cap_t *cap;
    const char test_file[] = "16ch_quadspi_100mHz.bin.gz";
    FILE *fp = fopen(test_file, "rb");
    int rc;

    /* Init SPI decoder and map physical channels to logical ones */
    pa_spi_ctx_init(&spi_ctx);
    pa_spi_ctx_map_mosi(spi_ctx, 0);
    pa_spi_ctx_map_miso(spi_ctx, 1);
    pa_spi_ctx_map_sclk(spi_ctx, 2);
    pa_spi_ctx_map_cs(spi_ctx, 3);
    pa_spi_ctx_set_flags(spi_ctx, SPI_FLAG_ENDIANESS);

    /* Map sample file into memory */
    // XXX - need to convert these to text fixtures!
    rc = saleae_import_analog(fp, &cap);
    if (rc) {
        printf("rc: %d\n", rc);
    }

    for (unsigned long i = 0; i < cap_get_nsamples((cap_t *) dcap); i++)
    {
        uint32_t sample;
        uint8_t dout, din;
        int rc;
        sample = cap_digital_get_sample(dcap, i);
        rc = pa_spi_stream(spi_ctx, sample, &dout, &din);
        if (PA_SPI_DATA_VALID == rc) {
            decode_count++;
        }
        sample_count++;
    }

    ASSERT_TRUE(decode_count > 0);
    ASSERT_TRUE(sample_count > 0);

    pa_spi_ctx_cleanup(spi_ctx);
    fclose(fp);
#endif
}
