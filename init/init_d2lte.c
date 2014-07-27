/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties();
void cdma_properties(char cdma_subscription[],
                     char default_network[],
                     char operator_numeric[],
                     char operator_alpha[],
                     char sms_pseudo_multipart[]);

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I747M")) {
        /* d2can */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/d2vl/d2can:4.4.2/KOT49H/I747MVLUFNE6:user/release-keys");
        property_set("ro.build.description", "d2vl-user 4.4.2 KOT49H I747MVLUFNE6 release-keys");
        property_set("ro.product.device", "d2can");
        property_set("ro.product.model", "SGH-I747M");
    } else if (strstr(bootloader, "I747")) {
        /* d2att */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/d2uc/d2att:4.3/JSS15J/I747UCUEMJB:user/release-keys");
        property_set("ro.build.description", "d2uc-user 4.3 JSS15J I747UCUEMJB release-keys");
        property_set("ro.product.device", "d2att");
        property_set("ro.product.model", "SAMSUNG-SGH-I747");
    } else if (strstr(bootloader, "R530C")) {
        /* d2cri */
        cdma_properties("0", "8", "310090", "Cricket", "0");
        property_set("ro.build.fingerprint", "samsung/d2cri/d2cri:4.4.2/KOT49H/R530CVVUDNE4:user/release-keys");
        property_set("ro.build.description", "d2cri-user 4.4.2 KOT49H R530CVVUDNE4 release-keys");
        property_set("ro.product.model", "SCH-R530C");
        property_set("ro.product.device", "d2cri");
    } else if (strstr(bootloader, "SC06D")) {
        /* d2dcm */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/d2om/d2dcm:4.1.2/JZO54K/SC06DOMBMF1:user/release-keys");
        property_set("ro.build.description", "d2om-user 4.1.2 JZO54K SC06DOMBMF1 release-keys");
        property_set("ro.product.model", "SC-06D");
        property_set("ro.product.device", "d2dcm");
        property_set("ro.ril.enable.dcm.feature", "1");
    }  else if (strstr(bootloader, "R530M")) {
        /* d2mtr */
        cdma_properties("0", "8", "311660", "MetroPCS", "0");
        property_set("ro.build.fingerprint", "samsung/d2mtr/d2mtr:4.1.2/JZO54K/R530MVQAMF2:user/release-keys");
        property_set("ro.build.description", "d2mtr-user 4.1.2 JZO54K R530MVQAMF2 release-keys");
        property_set("ro.product.model", "SCH-R530M");
        property_set("ro.product.device", "d2mtr");
    } else if (strstr(bootloader, "L710")) {
        /* d2spr and d2spi */
        cdma_properties("1", "8", "310120", "Sprint", "1");
        property_set("ro.build.fingerprint", "samsung/d2spr/d2spr:4.4.2/KOT49H/L710VPUDND8:user/release-keys");
        property_set("ro.build.description", "d2spr-user 4.4.2 KOT49H L710VPUDND8 release-keys");
        property_set("ro.product.model", "SPH-L710");
        property_set("ro.product.device", "d2spr");
    } else if (strstr(bootloader, "S960L")) {
        /* d2tfnspr */
        cdma_properties("1", "8", "310120", "Sprint", "1");
        property_set("ro.build.fingerprint", "samsung/d2tfnspr/d2tfnspr:4.1.2/JZO54K/S960LWYAMD6:user/release-keys");
        property_set("ro.build.description", "d2tfnspr-user 4.1.2 JZO54K S960LWYAMD6 release-keys");
        property_set("ro.product.model", "SCH-S960L");
        property_set("ro.product.device", "d2tfnspr");
    } else if (strstr(bootloader, "T999")) {
        /* d2tmo */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/d2tmo/d2tmo:4.3/JSS15J/T999UVUEMJC:user/release-keys");
        property_set("ro.build.description", "d2tmo-user 4.3 JSS15J T999UVUEMJC release-keys");
        property_set("ro.product.model", "SGH-T999");
        property_set("ro.product.device", "d2tmo");
    } else if (strstr(bootloader, "R530U")) {
        /* d2usc */
        cdma_properties("0", "8", "311580", "U.S.Cellular", "1");
        property_set("ro.build.fingerprint", "samsung/d2usc/d2usc:4.1.1/JRO03L/R530UVXALK5:user/release-keys");
        property_set("ro.build.description", "d2usc-user 4.1.1 JRO03L R530UVXALK5 release-keys");
        property_set("ro.product.model", "SCH-R530U");
        property_set("ro.product.device", "d2usc");
    } else if (strstr(bootloader, "I535")) {
        /* d2vzw */
        cdma_properties("0", "10", "311480", "Verizon", "0");
        property_set("ro.build.fingerprint", "Verizon/d2vzw/d2vzw:4.4.2/KOT49H/I535VRUDNE1:user/release-keys");
        property_set("ro.build.description", "d2vzw-user 4.4.2 KOT49H I535VRUDNE1 release-keys");
        property_set("ro.product.model", "SCH-I535");
        property_set("ro.product.device", "d2vzw");
    } else if (strstr(bootloader, "S968C")) {
        /* d2vzw - straighttalk */
        cdma_properties("1", "4", "310000", "TracFone", "0");
        property_set("ro.build.fingerprint", "Verizon/d2vzw/d2vzw:4.3/JSS15J/I535VRUCML1:user/release-keys");
        property_set("ro.build.description", "d2vzw-user 4.3 JSS15J I535VRUCML1 release-keys");
        property_set("ro.product.model", "SCH-S968C");
        property_set("ro.product.device", "d2vzw");
    } else if (strstr(bootloader, "I547")) {
        /* comanche */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/comancheuc/comancheatt:4.1.2/JZO54K/I547UCCMH5:user/release-keys");
        property_set("ro.build.description", "comancheuc-user 4.1.2 JZO54K I547UCCMH5 release-keys");
        property_set("ro.product.device", "comanche");
        property_set("ro.product.model", "SAMSUNG-SGH-I547");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void gsm_properties()
{
    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

void cdma_properties(char default_cdma_sub[], char default_network[],
                     char operator_numeric[], char operator_alpha[],
                     char sms_pseudo_multipart[])
{
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("telephony.sms.pseudo_multipart", sms_pseudo_multipart);

    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.cdma.subscribe_on_ruim_ready", "true");
    property_set("ro.ril.svdo", "true");
}
